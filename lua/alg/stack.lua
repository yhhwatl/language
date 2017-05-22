local stack = {}
function stack:new( ... )
	local t = {}
	setmetatable(t,{__index = stack})
	t:init()
	return t
end

function stack:init( ... )
	self.arr = {}
	self.top = -1
end
function stack:push( data )
	table.insert(self.arr,data)
	self.top = data
end

function stack:pop()
	local len = #self.arr
	if len <=0 then return nil end
	local data = self.arr[len]
	self.arr[len] = nil
	if len == 1 then
		self.top = -1
	else
		self.top = self.arr[len-1]
	end
	return data
end
return stack