package main

import (
	"Clippy/LinkedList"
	"context"
	"fmt"
	"os"
	"time"

	"golang.design/x/clipboard"
)

type Clipboard struct {
	watch   <-chan []byte
	History LinkedList.List[string]
	CopyAt  func(int)
}

func InitClipboard(ctx context.Context) *Clipboard {
	err := clipboard.Init()
	Pacman(err)

	cb := Clipboard{
		watch:   clipboard.Watch(ctx, clipboard.FmtText),
		History: LinkedList.CreateList[string](),
	}

	copyAt := func(i int) {
		clipboard.Write(clipboard.FmtText, []byte(*cb.History.GetAt(i)))

	}

	cb.CopyAt = copyAt
	return &cb
}

func ListenToClipboard(ctx context.Context, clipboard *Clipboard) {
	go func() {
		for clipboardChange := range clipboard.watch {
			clipboard.History.Unshift(string(clipboardChange))
		}
	}()

	<-ctx.Done()
}

func ExportClipboardHistory(clipboard *Clipboard) string {
	filename := fmt.Sprintf("history-%d.txt", time.Now().Unix())
	f, err := os.Create(filename)
	Pacman(err)

	clipboard.History.Traverse(func(s *string, index int) {
		_, err := f.WriteString(*s + "\n\n--\n\n")

		if err != nil {
			panic(err)
		}
	})

	Pacman(f.Close())

	return filename
}
