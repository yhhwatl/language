--功能：写入文件
--输入：文件名, 内容
--输出：生成的文件里面包含内容
function copyfile(source,destination)
	print(destination)
	sourcefile = io.open(source, "r")
	destinationfile = io.open(destination, "w")
	destinationfile:write(sourcefile:read("*all"))
	sourcefile:close()
	destinationfile:close()
end
local source = "/Volumes/HDD/Documents/workspace/language/README.md"
local destination = "/Volumes/HDD/Documents/workspace/wahaha.pb"
copyfile(source,destination)