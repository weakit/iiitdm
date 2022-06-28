package main

type ListNode[T any] struct {
	val  T
	prev *ListNode[T]
	next *ListNode[T]
}

type List[T any] struct {
	head *ListNode[T]
	tail *ListNode[T]
	size int
}

func CreateList[T any]() List[T] {
	return List[T]{head: nil, tail: nil, size: 0}
}

func (l List[T]) GetSize() int {
	return l.size
}

func (l *List[T]) Push(t T) {
	// empty list
	nodeToPush := ListNode[T]{val: t, next: nil}

	if l.size == 0 {
		l.head = &nodeToPush
		l.tail = &nodeToPush
	} else {
		l.tail.next = &nodeToPush
		nodeToPush.prev = l.tail
		l.tail = &nodeToPush
	}

	l.size++
}

func (l *List[T]) Unshift(t T) {
	// empty list
	nodeToUnshift := ListNode[T]{val: t, next: nil}

	if l.size == 0 {
		l.head = &nodeToUnshift
		l.tail = &nodeToUnshift
	} else {
		nodeToUnshift.next = l.head
		l.head.prev = &nodeToUnshift
		l.head = &nodeToUnshift
	}

	l.size++
}

func (l *List[T]) Traverse(f func(*T, int)) {
	if l.size <= 0 {
		return
	}

	count := 0
	node := l.head

	for node != nil {
		f(&node.val, count)
		node = node.next
		count += 1
	}
}

func (l *List[T]) TraverseUntil(f func(*T, int) bool) {
	if l.size <= 0 {
		return
	}

	count := 0
	node := l.head

	for node != nil {
		shouldBreak := !f(&node.val, count)

		if shouldBreak {
			break
		}

		node = node.next
		count += 1
	}
}

func (l *List[T]) GetAt(i int) *T {
	if i >= l.size || i < 0 {
		return nil
	}

	node := l.head

	for i > 0 {
		node = node.next
		i--
	}

	return &node.val
}
