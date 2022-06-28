package main

import (
	"fmt"
	"math"
	"strings"
	"time"

	tea "github.com/charmbracelet/bubbletea"
)

type model struct {
	clipboard      *Clipboard
	currentLoc     int
	optionsSize    int
	cursor         int
	selected       int
	windowHeight   int
	menu           string
	renderedList   string
	exportFilename string
	saidHi         bool
}

var historyMenuSize = 5

var mainMenuChoices = []string{
	"View clipboard History",
	"Export clipboard History",
}

func Min(nums ...int) int {
	min := math.MaxInt

	for _, num := range nums {
		if num < min {
			min = num
		}
	}

	return min
}

func newModel(clipboard *Clipboard) model {
	return model{
		optionsSize:  2,
		menu:         "main",
		selected:     -1,
		clipboard:    clipboard,
		cursor:       0,
		saidHi:       false,
		windowHeight: 12,
	}
}

type rememberMessage bool
type tickMessage time.Time
type selectMessage int

func rememberPerson() tea.Msg {
	return rememberMessage(true)
}

func tick() tea.Cmd {
	return tea.Every(50*time.Millisecond, func(t time.Time) tea.Msg {
		return tickMessage(t)
	})
}

func (m model) Init() tea.Cmd {
	return tea.Batch(tick(), tea.EnterAltScreen)
}

func (m *model) changeMenu(menu string) {
	// change menu along with option size
	switch menu {
	case "main":
		m.optionsSize = 2
	case "history":
		m.optionsSize = Min(historyMenuSize, m.clipboard.History.GetSize())
	default:
		m.optionsSize = 0
	}

	m.menu = menu
	m.cursor = 0
	m.currentLoc = 0
}

func (m model) handleMainMenuKeys(msg tea.KeyMsg) (tea.Model, tea.Cmd) {
	switch msg.String() {

	case "ctrl+c", "q":
		m.menu = "none"
		return m, tea.Quit

	case "up", "k":
		if m.cursor > 0 {
			m.cursor--
		}

	case "down", "j":
		if m.cursor < m.optionsSize-1 {
			m.cursor++
		}

	case "enter", " ":
		m.selected = m.cursor
		return m, tea.Batch(rememberPerson, func() tea.Msg {
			return selectMessage(m.selected)
		})
	}

	return m, nil
}

func (m model) handleHistoryKeys(msg tea.KeyMsg) (tea.Model, tea.Cmd) {
	switch msg.String() {

	case "ctrl+c":
		m.menu = "none"
		return m, tea.Quit

	case "q":
		m.changeMenu("main")

	case "up", "k":
		if m.cursor > 0 {
			m.cursor--
		} else if m.currentLoc > 0 {
			m.currentLoc--
		}

	case "down", "j":
		if m.cursor < m.optionsSize-1 {
			m.cursor++
		} else if m.currentLoc+m.cursor+1 < m.clipboard.History.GetSize() {
			m.currentLoc++
			m.renderedList, m.optionsSize = renderHistoryList(m)

			// ensure required element is present on screen
			for m.currentLoc+m.optionsSize <= m.cursor {
				m.currentLoc++
				m.renderedList, m.optionsSize = renderHistoryList(m)
			}

			// make sure cursor is last element
			m.cursor = m.optionsSize - 1
		}

	case "enter", " ":
		if m.clipboard.History.GetSize() > 0 {
			m.clipboard.CopyAt(m.currentLoc + m.cursor)
		}
	}

	return m, nil
}

func (m model) Update(msg tea.Msg) (tea.Model, tea.Cmd) {
	switch msg := msg.(type) {

	case tickMessage:
		// perform tick updates
		if m.menu == "history" {
			m.renderedList, m.optionsSize = renderHistoryList(m)
		}

		return m, tick()

	case rememberMessage:
		m.saidHi = true

	case tea.WindowSizeMsg:
		m.windowHeight = msg.Height

	case selectMessage:
		if m.menu == "main" {
			switch int(msg) {
			case 0:
				m.changeMenu("history")
			case 1:
				if m.clipboard.History.GetSize() > 0 {
					m.exportFilename = ExportClipboardHistory(m.clipboard)
				} else {
					m.exportFilename = "null"
				}
				m.changeMenu("export")
			}
		}

	case tea.KeyMsg:
		if m.menu == "main" {
			return m.handleMainMenuKeys(msg)
		}

		if m.menu == "history" {
			return m.handleHistoryKeys(msg)
		}

		m.changeMenu("main")
	}

	return m, nil
}

func renderMainMenu(m model) string {
	s := ""

	if !m.saidHi {
		s += "\nHi! I'm Clippy!\nI've started keeping track of the clipboard now."
	} else {
		s += "\nClippy~!\nI'm still tracking the clipboard."
	}

	historySize := m.clipboard.History.GetSize()

	if historySize == 1 {
		s += "\nRemembering 1 thing!\n"
	} else if historySize >= 5 {
		s += fmt.Sprintf("\nRemembering %d things. (that's a lot!)\n", historySize)
	} else {
		s += fmt.Sprintf("\nRemembering %d things.\n", historySize)
	}

	s += "\nYou can:\n"

	for i, option := range mainMenuChoices {
		if m.cursor == i {
			s += SelectedOptionStyle.Render("\n> " + option)
		} else {
			s += "\n  " + option
		}
	}

	s += "\n\nOr you can press Q to quit!\n"

	return s
}

func renderHistoryList(m model) (string, int) {
	s := ""
	linesLeft := m.windowHeight - 5
	options := 0
	historyToSkip := m.currentLoc

	m.clipboard.History.TraverseUntil(func(obj *string, count int) bool {
		if historyToSkip > 0 {
			historyToSkip--
			return true
		}

		text := RenderCopiedText(count, m.cursor+m.currentLoc == count, *obj)
		linesTaken := strings.Count(text, "\n") + 2

		if linesTaken > linesLeft {
			return false
		}

		linesLeft -= linesTaken
		s += text + "\n\n"
		options++
		return true
	})

	if m.clipboard.History.GetSize() == 0 {
		s += "I don't remember anything yet. Try copying something."
	}

	s += strings.Repeat("\n", linesLeft)

	s += RenderKeybinds(
		Keybind{"↑/↓", "change entry"},
		Keybind{"enter", "copy entry"},
		Keybind{"Q", "go back"},
	)

	return s, options
}

func renderHistoryMenu(m model) string {
	historySize := m.clipboard.History.GetSize()

	s := "\nClippy's Recent Memories: "

	if historySize == 0 {
		s += "Nothing.\n\n"
	} else if historySize > 4 {
		s += fmt.Sprintf("%d things! (nice copying!)\n\n", historySize)
	} else if historySize == 1 {
		s += fmt.Sprintf("%d thing.\n\n", historySize)
	} else {
		s += fmt.Sprintf("%d things.\n\n", historySize)
	}

	s += m.renderedList

	return s
}

func renderExportMenu(m model) string {
	s := "\nClippy's Exports"

	if m.exportFilename != "null" {
		s += "\n\nClippy has successfully exported the clipboard history!"
		s += "\n\nYou can find it in " + m.exportFilename + "!"
	} else {
		s += "\n\nClippy does not have any history to export."
		s += "\n\nTry copying something maybe?"
	}

	s += strings.Repeat("\n", m.windowHeight-7)
	s += RenderKeybinds(Keybind{"any key", "to go back"})

	return s
}

func (m model) View() string {
	s := ""

	switch m.menu {
	case "main":
		s = renderMainMenu(m)
	case "history":
		s = renderHistoryMenu(m)
	case "export":
		s = renderExportMenu(m)
	case "none":
		s = ""
	default:
		s = "\nThis is not supposed to happen? :/"
	}

	return LeftPadding.Render(s)
}

func ListenToTea(clipboard *Clipboard) {
	p := tea.NewProgram(newModel(clipboard), tea.WithAltScreen())

	if err := p.Start(); err != nil {
		panic(err)
	}
}
