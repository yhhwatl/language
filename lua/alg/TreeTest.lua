local stack = require("./stack")
local TreeNode = {}
function TreeNode:new( op )
	local t = {}
	setmetatable(t,{__index = TreeNode})
	t:ctor(op)
	return t
end
function TreeNode:ctor( op )
	op = op or {}
	self.data = op.data
	self.lChild = nil
	self.rChild = nil
	self.parent = nil
end
local str = ""
function createTree( op, lChild, rChild )
	local tNode = TreeNode:new(op)
	tNode.lChild = lChild
	tNode.rChild = rChild
	if lChild then lChild.parent = tNode end
	if rChild then rChild.parent = tNode end
	return tNode
end
-- 中序遍历
function transLMR( root )
	-- if root then
	-- 	transLMR(root.lChild)
	-- 	str = str .." ".. root.data
	-- 	transLMR(root.rChild)
	-- end

	local s = stack:new()
	local t = root
	while (t or s.top ~= -1) do
		while t do
			s:push(t)
			t = t.lChild
		end
		local v = s:pop()
		str = str.." "..v.data
		t = v.rChild
	end
end
-- 前序遍历
function transMLR( root )
	if root then
		str = str .." ".. root.data
		transMLR(root.lChild)
		transMLR(root.rChild)
	end
end
-- 后序遍历
function transLRM( root )
	if root then
		transLRM(root.rChild)
		transLRM(root.lChild)
		str = str .." ".. root.data
	end
end
-- 二叉搜索树
function searchKey( root, key )
	if root == nil or key == root.data then
		return root
	end
	-- if root.data > key then
	-- 	return findKey(root.lChild,key)
	-- else
	-- 	return findKey(root.rChild,key)		
	-- end
	while root and key ~= root.data do
		if root.data > key then
			root = root.lChild
		else
			root = root.rChild
		end
	end
	return root
end
-- 二叉搜索树插入
-- 理应插入叶子结点上，由于插入和删除的顺序不可控，我们需要采取一些积极的措施
function insertNode( root, node )
	local curNode = root
	local tmpNode = nil
	local preNode = nil
	local nodes = {createTree({data = -1}),root}
	while curNode do
		tmpNode = curNode
		preNode = nodes[#nodes-1] 
		if node.data < curNode.data then
			curNode = curNode.lChild
		else
			curNode = curNode.rChild
		end
		nodes[#nodes+1] = curNode
	end
	if not tmpNode then 
		root = node
	else
		if preNode.data > node.data then
			preNode.lChild = node
		else
			preNode.rChild = node
		end
		node.parent = preNode

		if node.data < tmpNode.data then
			node.rChild = tmpNode
		else
			node.lChild = tmpNode
		end
		tmpNode.parent = node		
	end
end
function removeNode( root, node )
	local curNode = root
	local tmpNode = nil
	local preNode = nil
	local nodes = {createTree((data = -1)),root}
	local flag = 0
	while curNode do
		tmpNode = curNode
		preNode = nodes[#nodes-1]
		if node.data == curNode.data then 
			flag = 1
			break 
		end
		if node.data < curNode.data then
			curNode = curNode.lChild
		else
			curNode = curNode.rChild
		end
		nodes[#nodes+1] = curNode
	end
	if not tmpNode then 
		return
	else
		if flag == 0 then
			print("not find")
			return
		end
		if  root.lChild or root.rChild then
			
		else
			root = nil
		end
	end
end
function main( ... )
	local n10 = createTree({data = 13})
	local n9 = createTree({data = 4})
	local n8 = createTree({data = 2})
	local n7 = createTree({data = 7},nil,n10)
	local n6 = createTree({data = 3},n8,n9)
	local n5 = createTree({data = 20})	
	local n4 = createTree({data = 17})
	local n3 = createTree({data = 6},n6,n7)
	local n2 = createTree({data = 18},n4,n5)
	local n1 = createTree({data = 15},n3,n2)
	-- transLMR(n1) -- 4251637
	-- transMLR(n1) -- 1245367
	-- transLRM(n1) -- 7361524
	-- print(str)
	-- local n = searchKey(n1,7)
	-- print(n.data)
	insertNode(n1,createTree({data = 8}))
	transLMR(n1)
	print(str)
end
main()
















