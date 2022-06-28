package main

import (
	"context"
	"fmt"
)

func Pacman(err error) {
	if err != nil {
		panic(err)
	}
}

func main() {
	// create contexts
	bCtx := context.Background()
	ctx := context.WithValue(bCtx, "list", CreateList[string]())

	// initialize clipboard library
	clipboard := InitClipboard(ctx)

	// run go routines
	go ListenToClipboard(ctx, clipboard)
	ListenToTea(clipboard)
	fmt.Println("\nBye-bye!\n")
}
