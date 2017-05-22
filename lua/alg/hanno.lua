local count = 0
function hanno( n, x, y, z )
	if n == 0 then
		return 1
	else
		hanno(n-1,x,z,y)
		print("%c->%c",x,y)
		count = count + 1
		hanno(n-1,z,y,x)
	end
end
hanno(6,'A','B','C')
print("use times = ",count)

function getSum( n )
	if n == 0 then
		return 0
	else
		return n + getSum(n-1)
	end
end
local sum = getSum(5)
print(sum)

function getFactorial( n )
	if n == 0 then
		return 1
	else
		return n * getFactorial(n-1)
	end
end
local fac = getFactorial(5)
print(fac)

function getFibon( n )
	if n == 0 then return 0 end
	if n == 1 then return 1 end
	return getFibon(n-1) + getFibon(n-2)
end

local fb = getFibon(6)
print(fb)













