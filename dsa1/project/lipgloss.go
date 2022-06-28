package main

import (
	"fmt"
	"strings"

	"github.com/charmbracelet/lipgloss"
)

const maxParagraphWidth = 40
const maxParagraphHeight = 4
const maxParagraphSize = maxParagraphHeight*maxParagraphWidth - 2

const dimGrey = lipgloss.Color("#808080")
const stacyPink = lipgloss.Color("#FF5F87")

var LeftPadding = lipgloss.NewStyle().PaddingLeft(1)

var SelectedOptionStyle = lipgloss.NewStyle().
	Bold(true).
	Foreground(stacyPink)

var copiedTextParagraph = lipgloss.NewStyle().
	Width(maxParagraphWidth).
	MaxWidth(maxParagraphWidth).
	MaxHeight(4).
	Align(lipgloss.Left)

var copiedTextBorder = lipgloss.NewStyle().
	BorderStyle(lipgloss.NormalBorder()).
	BorderForeground(lipgloss.NoColor{}).
	PaddingLeft(1).PaddingRight(1)

var cursorStyle = copiedTextParagraph.Copy().
	PaddingRight(1).
	Width(1).
	Foreground(dimGrey)

var selectedCursorStyle = cursorStyle.Copy().
	Bold(true).
	Foreground(stacyPink)

var dimStyle = lipgloss.NewStyle().Foreground(dimGrey)

type Keybind struct {
	keybind string
	action  string
}

func RenderKeybinds(keybinds ...Keybind) string {
	if len(keybinds) == 0 {
		return ""
	}

	s := keybinds[0].keybind + " " + dimStyle.Render(keybinds[0].action)

	for _, keybind := range keybinds[1:] {
		s += " • "
		s += keybind.keybind
		s += " "
		s += dimStyle.Render(keybind.action)
	}

	return s
}

func processParagraphString(s string) string {
	s = strings.Trim(s, " \n\t")
	s = copiedTextParagraph.Render(s)
	returnString := ""

	newLines := 0
	currentLineChars := 0
	totalChars := 0

	for _, char := range []rune(s) {
		if char == '\n' || currentLineChars >= maxParagraphWidth {
			newLines++
			currentLineChars = 0
		} else {
			currentLineChars++
		}

		returnString += string(char)
		totalChars++

		if newLines >= maxParagraphHeight || totalChars >= maxParagraphSize {
			returnString = strings.Trim(returnString, "\n") + "…"
			break
		}
	}

	return copiedTextParagraph.Render(returnString)
}

func RenderCopiedText(count int, selected bool, copiedText string) string {
	paragraph := processParagraphString(copiedText)

	cursor := "\n "
	renderCursorStyle := cursorStyle

	if selected {
		cursor = "\n>"
		renderCursorStyle = selectedCursorStyle
	}

	return lipgloss.JoinHorizontal(
		lipgloss.Top,
		renderCursorStyle.Render(cursor),
		renderCursorStyle.Render(fmt.Sprintf("\n%d", count+1)),
		copiedTextBorder.Render(paragraph),
	)
}
