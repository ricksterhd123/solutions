-- Caesar cipher script haskell
import Data.Char

plainToCipher :: Char -> Char
plainToCipher p = chr((rem (ord (toLower p) - (97 + 3)) 26) + 97) 

cipherToPlain :: Char -> Char
cipherToPlain c =  chr ((rem (ord (toLower c) - (97 - 3)) 26) + 97)

caesarEncrypt :: String -> String
caesarEncrypt (x:xs) = plainToCipher x : caesarEncrypt xs 
caesarEncrypt [] = []

caesarDecrypt :: String -> String
caesarDecrypt (x:xs) = cipherToPlain x : caesarDecrypt xs
caesarDecrypt [] = []

-- TODO: learn how to process user input yet.
caesarEncrypt' :: [IO ()] -> IO ()
caesarEncrypt' [] = return ()
caesarEncrypt' str = do caesarEncrypt str

main = do 
    putStrLn "Please enter a string: "
    plainText <- getLine
    cipherText <- caesarEncrypt' plainText
    print cipherText
    --print "Plain text: " : caesarEncrypt(plainText)
    -- print "\n"
    -- print "Cipher text: " : caesarEncrypt(plainText :: String)
    -- print "\n"