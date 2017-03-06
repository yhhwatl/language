
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
end
function createTree( op, lChild, rChild )
	local tNode = TreeNode:new(op)
	tNode.lChild = lChild
	tNode.rChild = rChild
	return tNode
end
local n4 = createTree({data = 4})
local n5 = createTree({data = 5})
local n6 = createTree({data = 6})
local n7 = createTree({data = 7})
local n2 = createTree({data = 2},n4,n5)
local n3 = createTree({data = 3},n6,n7)
local n1 = createTree({data = 1},n2,n3)
local str = ""
function transLMR( root )
	if root then
		transLMR(root.lChild)
		str = str .. root.data
		transLMR(root.rChild)
	end
end
function transMLR( root )
	if root then
		str = str .. root.data
		transMLR(root.lChild)
		transMLR(root.rChild)
	end
end
function transRML( root )
	if root then
		transRML(root.rChild)
		str = str .. root.data
		transRML(root.lChild)
	end
end
-- transLMR(n1) -- 4251637
-- transMLR(n1) -- 1245367
-- transRML(n1) -- 7361524
print(str)


