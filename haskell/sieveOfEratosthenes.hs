import Data.List
-- Generate sieve recursively

sieve :: [Int] -> Int -> [Int]
sieve [] p = []
sieve list p
    | length b == 0 = sieved
    | otherwise = sieve sieved (head b)
    where 
        sieved = filter (\x -> x `mod` p == 0) (filter (\x -> x >= 2*p) list)
        b = filter (\x -> x > p) sieved

-- Sieve of eratosthenes
-- intepreted by me using wiki

primeSieve :: Int -> [Int]
primeSieve n = a \\ sieve a 2
    where a = [2..n]  -- complete list

