local data = require('aoc2022-4-data')

-- [[2-4,6-8
-- 2-3,4-5
-- 5-7,7-9
-- 2-8,3-7
-- 6-6,4-6
-- 2-6,4-8]]

function table.map(t, f)
    local k = {}
    for i, v in ipairs(t) do
        k[i] = f(v)
    end
    return k
end

function table.filter(t, f)
    local k = {}
    for _, v in ipairs(t) do
        if f(v) then
            table.insert(k, v)
        end
    end
    return k
end

-- https://stackoverflow.com/questions/1426954/split-string-in-lua
local function split(inputstr, sep)
    if sep == nil then
        sep = "%s"
    end

    local t = {}
    for str in string.gmatch(inputstr, "([^" .. sep .. "]+)") do
        table.insert(t, str)
    end

    return t
end

local function decodePair(pairstr)
    local matched, _, x1, y1, x2, y2 = string.find(pairstr, "(%d+)-(%d+),(%d+)-(%d+)")
    if not matched then
        return false
    end
    return { tonumber(x1), tonumber(y1), tonumber(x2), tonumber(y2) }
end

function isPairContained(t)
    local size1 = math.abs(t[1] - t[2])
    local size2 = math.abs(t[3] - t[4])

    if size1 < size2 then
        return t[3] <= t[1] and t[1] <= t[3] + size2 - size1
    end

    return t[1] <= t[3] and t[3] <= t[1] + size1 - size2
end

function isPairOverlapped(t)
    local size1 = math.abs(t[1] - t[2])
    local size2 = math.abs(t[3] - t[4])

    if size1 < size2 then
        return t[2] >= t[3] and t[1] <= t[4]
    end

    return t[4] >= t[1] and t[3] <= t[2] 
end

local paires = split(data, "\n")
local decodedPairs = table.map(paires, decodePair)
local containedPairs = table.filter(decodedPairs, isPairContained)
local overlappedPairs = table.filter(decodedPairs, isPairOverlapped)

print("Got "..tostring(#containedPairs) .." pairs containing eachother")
print("Got "..tostring(#overlappedPairs) .." pairs overlapping eachother")
