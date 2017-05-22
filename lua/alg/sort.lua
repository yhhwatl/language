local arr = {2,8,9,4,3,7,6}
function magre( arr, p, q, r)
	-- local arr = {2,4,7,1,5,9}
	-- local p,q,r = 1,4,#arr
	while arr[p] and arr[q] and p <= q and q <= r do
		if arr[p] > arr[q] then
			local x = arr[p]
			arr[p] = arr[q]
			arr[q] = x
			p = p + 1
		else
			q = q + 1
		end	
	end
	-- local len1 = q - p
	-- local len2 = r - q
	-- local len = math.min(len1,len2)
	-- local x = {}
	-- local min = arr[p]
	-- for i=1,len do
	-- 		if arr[p] < arr then
	-- 			min = arr[p]
	-- 		end
	-- end
	return arr
end
-- 选择排序
function selectSort( arr, n )
	local t = {}
	for i=1,n do
		local min = arr[i]
		local h = i
		for j=i+1,n do
			if arr[j] < min then
				min = arr[j]
				h = j
			end
		end
		local x = arr[i]
		arr[i] = arr[h]
		arr[h] = x
	end
end
-- 插入排序
function insertSort( arr, n )
	for j=2,n do
		local i = j - 1
		local key = arr[j]
		while i > 0 and arr[i] > key do
			arr[i+1] = arr[i]
			i = i - 1
		end
		arr[i+1] = key
	end
end

-- insertSort(arr,#arr)
-- selectSort(arr,#arr)
arr = magre()
for k,v in pairs(arr) do
	print(k,v)
end