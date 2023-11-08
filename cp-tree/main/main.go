package main

import "fmt"

type node[T any] struct {
	ValueT T
	Left   *node[T]
	Right  *node[T]
	// Parent *node[T]
}

type Node[T any] interface {
	get_size(*node[T]) int
	get_height(*node[T]) int
}

func newNode[T any](data T) *node[T] {
	return &node[T]{
		ValueT: data,
		Left:   nil,
		Right:  nil,
		// Parent: nil,
	}
}

func get_size[T any](root *node[T]) int {
	if root == nil {
		return 0
	}
	return 1 + get_size(root.Left) + get_size(root.Right)
}

func get_height[T any](root *node[T]) int {
	if root == nil {
		return -1
	}
	var leftHeight = get_height(root.Left)
	var rightHeight = get_height(root.Right)
	if leftHeight > rightHeight {
		return 1 + leftHeight
	} else {
		return 1 + rightHeight
	}
}

func PrintTree[T any](root *node[T]) {
	if root == nil {
		return
	}
	fmt.Print(root.ValueT, " ")
	PrintTree(root.Left)
	PrintTree(root.Right)
}

func main() {
	var root node[int]
	root.ValueT = 0
	root.Left = newNode[int](5)
	root.Right = newNode[int](10)
	root.Left.Left = newNode[int](15)
	root.Left.Right = newNode[int](12)
	root.Left.Left.Left = newNode[int](20)
	root.Left.Left.Right = newNode[int](22)
	PrintTree[int](&root)
	fmt.Println()
	fmt.Println(get_size[int](&root))
	fmt.Println(get_height[int](&root))
}

/*
        0
       / \
      5  10
    / \
   15 12
  / \
 20 22
*/
