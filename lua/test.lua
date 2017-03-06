-- test.lua
function transTable( table )
	if table == nil then
		return nil
	end
	for k,v in pairs(table) do
		if type(v) == "table" then
			transTable(v)
		else
			print(k,v)
		end
	end
end
local t = {
	x = 1,
	y = {
		a = {
			1,2,3,7,8,9		
		},
		b = 5,
	},	
	z = 4,
}
transTable(t)
