-- Caesar cipher script haskell
import Data.Char

plainToCipher :: Char -> Char
plainToCipher p = chr((rem (ord (toLower p) - (97 - 3)) 26) + 97) 

cipherToPlain :: Char -> Char
cipherToPlain c =  chr ((rem (ord (toLower c) - (97 + 3)) 26) + 97)

caesarEncrypt :: String -> String
caesarEncrypt (x:xs)
    | x == ' '  = x : caesarEncrypt xs
    | otherwise = plainToCipher x : caesarEncrypt xs
 
caesarEncrypt [] = []

caesarDecrypt :: String -> String
caesarDecrypt (x:xs)
    | x == ' '  = x : caesarDecrypt xs
    | otherwise = cipherToPlain x : caesarDecrypt xs
caesarDecrypt [] = []

parseMode :: String -> Int
parseMode (x:xs)
    | x == '1' = 1
    | x == '2' = 2
    | otherwise = -1 -- invalid mode

main = do
    putStrLn "================================="
    putStrLn "=         Enter mode            ="
    putStrLn "================================="
    putStrLn "=  1. Encrypt                   ="
    putStrLn "=  2. Decrypt                   ="
    putStrLn "================================="
    putStrLn "Please select a mode [1-2]: "
    txtMode <- getLine
    let mode = parseMode txtMode
    if mode == -1
        then return ()
    else do
        putStrLn "$:> "
        plainText <- getLine
        if null plainText
            then return ()
        else do
            if mode == 1
                then putStrLn $ caesarEncrypt plainText
            else do
                putStrLn $ caesarDecrypt plainText
    main