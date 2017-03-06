local Node = {}
Node.__index = Node
function Node:ctor( ... )
	-- print("Node ctor")
	return self
end
function Node:setIndex( idx )
	print("Node setIndex")
end

return Node