
local lfs = require"lfs"
print (lfs._VERSION)
local tmp = "/tmp"
local sep = string.match (package.config, "[^\n]+")
local upper = ".."


function attrdir (path)
    for file in lfs.dir(path) do
        if file ~= "." and file ~= ".." then
            local f = path..sep..file
            -- print ("\t=> "..file.." <=")
            local i = string.find(file,".meta")
            if i then
                print(i)
               os.remove(f)
            else
                local attr = lfs.attributes (f)
                assert (type(attr) == "table")
                if attr.mode == "directory" then
                        attrdir (f)
                end
            end       
        end
    end
end
local root = "/Volumes/HDD/Downloads/chrom/LuaFramework_UGUI-master/Assets/LuaFramework"
attrdir(root)