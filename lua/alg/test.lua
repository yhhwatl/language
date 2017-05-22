local str = "abbabcs"
print(string.len(str))
function S2T( str )
	local t = type(str)
	if t == "nil" or str == "" then 
		return nil 
	elseif t == "number" or t == "boolean" or t == "string" then
		str = tostring(str)
	end
	local ret = "return "..str
	local func = loadstring(ret)
	if func== nil then 
		t = {} 
	else
		t = func()
	end
	if t == nil then  
		t = {}
		for i=1,#str do
			table.insert(t,string.sub(str,i,i))
		end
		return t
	else
		return t
	end
end
function maxSubLen( str )
	-- local inStr = function ( st, c )
	-- 	for i=1,#st do
	-- 		if st[i] == c then
	-- 			return true
	-- 		end
	-- 	end
	-- 	return false
	-- end

	-- local doub = function ( s )
	-- 	local sLen = string.len(s)
	-- 	local st = S2T(s)
	-- 	local tmp = {}
	-- 	for i=1,sLen do
	-- 			if inStr(st,st[i]) then
	-- 				if not tmp[st[i]] then
	-- 					tmp[st[i]] = 1
	-- 				else
	-- 					return true
	-- 				end
	-- 			end		
	-- 	end
	-- 	return false
	-- end
	-- local t = {}
	local maxLen = 0
	local len = string.len(str)
	-- for i=len,1,-1 do
	-- 	for j=1,i do
	-- 		local sub = string.sub(str,j,i)
	-- 		if not doub(sub) then
	-- 			maxLen = math.max(maxLen,string.len(sub))
	-- 		end
	-- 	end
	-- end
	print(string.byte('z'))
	local i,j = 1,1
	local has = {}
	for i= string.byte('A'),string.byte('z') do
		has[string.char(i)] = false
	end
	local st = S2T(str)
	while(true) do
		while(j < len and (not has[st[j]])) do
			has[st[j]] = true
			j = j + 1
		end
		maxLen = math.max(maxLen,j-i+1)
		if j >= len then break end
		while (st[i] ~= st[j]) do
			has[st[i]] = false
			i = i + 1
		end
		has[st[i]] = false
		i = i + 1
	end
	return maxLen
end
local ml = maxSubLen(str)
print(ml)
-- local t = {4,2,5,1,7,3,9,6,8}
-- function qsort( arr,left,right)
-- 	if left >= right then
-- 		return--递归出口
-- 	end
-- 	local i,j = left,right
-- 	local key = arr[i]
-- 	while(i < j) do
-- 		while(i < j and arr[j] >= key) do
-- 				j = j  - 1
-- 		end
-- 		arr[i] = arr[j]
-- 		while(i < j and arr[i] <= key) do
-- 			i = i + 1
-- 		end
-- 		arr[j] = arr[i]
-- 	end
-- 	arr[i] = key -- 关键key入位
-- 	qsort(arr,left,i-1)
-- 	qsort(arr,i+1,right)
-- end
-- -- qsort(t,1,9)
-- for k,v in pairs(t) do
-- 	print(k,v)
-- end
-- local t = {2,4,3,8,5,4,1}
-- local len = #t
-- print(len)
-- local max = 0
-- local cur = ""
-- for i=1,len-1 do
-- 	local sum = 0
-- 	local tur = ""
-- 	for j=i,#t,2 do
-- 		sum = sum + t[j]
-- 		tur = tur ..j.." "
-- 	end
-- 	if max < sum then
-- 		max = sum
-- 		cur = tur
-- 	end
-- end
-- print(max)
-- print(cur)
-- local str = "I'm a student"
-- function split( s,flag )
-- 	local str = s
-- 	local i,j = 1,1
-- 	local t = {}
-- 	if not string.find(str,flag) then
-- 		return t
-- 	end
-- 	while true do
-- 		j = string.find(str,flag)
-- 		print(j)
-- 		if j == nil then table.insert(t,str) break  end
-- 		local temp = string.sub(str,i,j-1)
-- 		table.insert(t,temp)
-- 		print(i,temp)
-- 		str = string.sub(str,j+1,#str)
-- 		print(i,j,str)
-- 	end
-- 	return t
-- end
-- local t = split(str," ")
-- local s = ""
-- for i=#t,1,-1 do
-- 	s = s .. t[i] .. " "
-- end
-- print(s)
-- local s = string.gsub("1 2 3",1,3)
-- print(s)
-- function S2T( str )
-- 	local t = type(str)
-- 	print(0)
-- 	if t == "nil" or str == "" then 
-- 		return nil 
-- 	elseif t == "number" or t == "boolean" or t == "string" then
-- 		str = tostring(str)
-- 	end
-- 	local ret = "return "..str
-- 	local func = loadstring(ret)
-- 	if func== nil then 
-- 		t = {} 
-- 	else
-- 		t = func()
-- 	end
-- 	if t == nil then  
-- 		t = {}
-- 		for i=1,#str do
-- 			table.insert(t,string.sub(str,i,i))
-- 		end
-- 		return t
-- 	else
-- 		return t
-- 	end
-- end


-- local str  = "angelbaby"
-- str = "return ".. str
-- local func = loadstring(str)
-- local t = func()
-- for k,v in pairs(t) do
-- 	print(k,v)
-- end

-- ‘A’ = ‘1’
-- ‘B’ = ‘2’
-- ‘C’ = '3'
-- 'D' = '4'
-- 'E' = '5'
-- 'F' = '6'
-- 'W' = '23'
-- 'X' = '24'
-- 'Y' = '25'
-- 'Z' = '26'
-- 。。。
-- ‘L’ = ‘12’
-- ‘AB’ = ‘12’
-- 'BF' = '26'
-- 'ABC' = '123'
-- '123' = 'ABC' = 'LC' = 'AW'
-- local c = string.byte("1",1)
-- print(c)
-- local s = string.char(49)
-- print(s)
-- -- in:'123'
-- -- out:'ABC' 'LC' 'AW'
-- function fn( str )
-- 	local t = {}
-- 	local len = string.len(str)
-- 	if len <= 0 then return {} 
-- 	elseif len == 1 then
-- 		return {string.char(string.byte(str,1) + 16)}	
-- 	else
-- 		for i=2,len do
-- 			local t1 = str[i-1]
-- 			local t2 = str[i]

-- 		end
-- 	end
-- end
-- local time = os.time()
-- local date = os.date("*t",  1490022000)
-- for k,v in pairs(date) do
-- 	print(k,v)
-- end
-- function crossMind( a,low,mind,high )
-- 	local left_sum = -9999
-- 	local sum = 0
-- 	local max_left = 0
-- 	for i= mind,-1,low do
-- 		sum = sum + a[i]
-- 		if sum > left_sum then
-- 			left_sum = sum
-- 			max_left = i
-- 		end
-- 	end
-- 	local right_sum = -9999
-- 	sum = 0
-- 	local max_right = 0
-- 	for j=mind+1,high do
-- 		sum = sum + a[j]
-- 		if sum > right_sum then
-- 			right_sum = sum
-- 			max_right = j
-- 		end
-- 	end
-- 	return max_left,max_right,left_sum+right_sum
-- end

-- function maxArr( a,low,high )
-- 	if low == high then
-- 		return low,high,a[low]
-- 	else
-- 		local mind = (low + high) / 2
-- 		mind = math.floor(mind)
-- 		local left_low,left_high,left_sum = maxArr(a,low,mind)
-- 		local right_low,right_high,right_sum = maxArr(a,mind+1,high)
-- 		local cross_low,cross_high,cross_sum = crossMind(a,low,mind,high)
-- 		-- return math.max(left_sum,right_sum,cross_sum)
-- 		if left_sum >= cross_sum and left_sum >= right_sum then
-- 			return left_low,left_high,left_sum
-- 		elseif right_sum >= left_sum and right_sum >= cross_sum then
-- 			return right_low,right_high,right_sum
-- 		else
-- 			return cross_low,cross_high,cross_sum
-- 		end	
-- 	end
-- end

-- function maxArr2( a )
-- 	local result = 0
-- 	local apply = a[1]
-- 	for i=1,#a do
-- 		if apply >= 0 then
-- 			apply  = apply + a[i]
-- 		else
-- 			apply = a[i]
-- 		end
-- 		if result < apply then
-- 			result = apply
-- 		end
-- 	end
-- 	return result
-- end

-- local a = {-16,-23,18,20,-7,12,-5,-22}
-- -- local i,j,sum = maxArr(a,1,8)
-- -- print(i,j,sum)
-- local result = maxArr2(a)
-- print(result)










-- --求最大和数组
-- local a = {1,4,-6,3,2,-1,9,-8,5,6}
-- function getMaxArr( a )
-- 	local totals = {}
-- 	local tIdx = 0
-- 	local index = 1
-- 	for i=1,#a do
-- 		local str = ""
-- 		local idx = 1
-- 		while idx <= #a - i + 1 do
-- 			tIdx = tIdx + 1
-- 			totals[tIdx] = {}
-- 			for j=0,i - 1 do
-- 				table.insert(totals[tIdx],a[idx+j])
-- 			end
-- 			idx = idx + 1
-- 		end
-- 		index = index + 1
-- 	end
-- 	return totals
-- end

-- local totals = getMaxArr(a)
-- local max = 0
-- local maxArr = {}
-- for k,v in pairs(totals) do
-- 	local temp = 0
-- 	for _,v1 in pairs(v) do
-- 		temp = temp + v1
-- 	end
-- 	if temp >= max then
-- 		max = temp
-- 		maxArr = v
-- 	end
-- end
-- print("maxArr :")
-- for k,v in pairs(maxArr) do
-- 	print(v)
-- end
-- print("sum: "..max)


-- function adjust( a,i,j )
-- 	local sum = 0
-- 	for k=i,j do
-- 		sum = sum + a[k]
-- 	end
-- 	return sum
-- end
-- local x = 1
-- function getMaxArr( a, n)
-- 	if n == 1 then
-- 		return adjust(a,1,1)
-- 	end
-- 	local sum = 0
-- 	local t = {}
-- 	for i=1,#a - n + 1 do
-- 		sum = math.max(sum,adjust(a,i,i + n - 1))
-- 	end
-- 	print("sum:"..sum)
-- 	return math.max(sum,getMaxArr(a,n-1))
-- end
-- local sum = getMaxArr(a,10)
-- print(sum)






