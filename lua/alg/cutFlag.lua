-- local s = "111"111",111" 

local strPath = "./String.lua"
local newFile = "./NewStr.lua"
local wp = io.open(newFile,"w")
for line in io.lines(strPath) do
	local con,i = string.find(line,"CONTENT")
	if con then
		-- local sIndex = string.find(line,"\"")
		local n1 = string.sub(line,1,i + 5)
		local ns = string.sub(line,i + 6,-4)
		local n2 = string.sub(line,-3,-1)
		local s = string.gsub(ns,"\"","'")
		wp:write(""..n1..s..n2.."\n")
	else
		wp:write(line..'\n')
	end
end
wp:close()