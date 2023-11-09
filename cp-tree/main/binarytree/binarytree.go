package binarytree

type node struct {
	Data   int
	Left   *node
	Right  *node
	Parent *node
}

func compare(l, r int) int {
	switch {
	case l < r:
		return -1
	case l > r:
		return 1
	default:
		return 0
	}
}

func FindNode(value int, r *node, parent *node) *node {
	var ptr *node
	for ptr != nil {
		cmp := compare(value, ptr.Data)
		if cmp == 0 {
			return ptr
		}
		if cmp < 0 {
			return ptr.Left
		} else {
			return ptr.Right
		}
	}
	return nil
}

func find_min_node(r *node) *node {
	// min := r
	// for min.Left != nil {
	// 	min = min.Left
	// }
	// return min
	if r.Left == nil {
		return r
	}
	return find_min_node(r.Left)
}

func find_max_node(r *node) *node {
	if r.Right == nil {
		return r
	}
	return find_max_node(r.Right)
}
