module Haskell1 where

import Control.Monad
import Data.Char
import Data.Function
import Data.List
import Data.Monoid
import Data.Time.Clock
import Data.Time.Format
import System.Directory

-- 1.2.7
lenVec3 x y z = sqrt (x ^ 2 + y ^ 2 + z ^ 2)

-- 1.2.10
sign x = if x > 0 then 1 else if x == 0 then 0 else -1

-- 1.3.8
a |-| b = abs (a - b)

-- 1.4.6
discount :: Double -> Double -> Double -> Double
discount limit proc sum = if sum >= limit then sum * (100 - proc) / 100 else sum

standardDiscount :: Double -> Double
standardDiscount = discount 1000 5

-- 1.4.9
twoDigits2Int :: Char -> Char -> Int
twoDigits2Int x y = if isDigit x && isDigit y then 10 * digitToInt x + digitToInt y else 100

-- 1.4.11
dist :: (Double, Double) -> (Double, Double) -> Double
dist p1 p2 = sqrt $ (fst p1 - fst p2) ^ 2 + (snd p1 - snd p2) ^ 2

-- 1.5.4
doubleFact :: Integer -> Integer
doubleFact n = if n <= 2 then n else n * doubleFact (n - 2)

-- 1.5.8
-- 1.5.10
fibonacci :: Integer -> Integer
fibonacci n = helper 0 1 n

helper p c 0 = p
helper p c n | n > 0 = helper c (p + c) (n - 1)
helper p c n | n < 0 = helper c (p - c) (n + 1)

-- 1.6.6
seqA :: Integer -> Integer
seqA n = let
    seqA' ppp pp p 0 = ppp
    seqA' ppp pp p 1 = pp
    seqA' ppp pp p 2 = p
    seqA' ppp pp p n = seqA' pp p (p + pp - 2 * ppp) (n - 1)
  in seqA' 1 2 3 n

-- 1.6.8
sum'n'count :: Integer -> (Integer, Integer)
sum'n'count x | x < 0     = sum'n'count (-x)
              | x < 10    = (x, 1)
              | otherwise = let (sum, count) = sum'n'count $ x `div` 10
                            in (sum + x `mod` 10, count + 1)

-- 1.6.9
integration :: (Double -> Double) -> Double -> Double -> Double
integration f a b = let
    h = (b - a) / 1000
    s = (f a + f b) / 2
    integration' acc x 0 = acc
    integration' acc x n = integration' (acc + f x) (x + h) (n - 1)
  in h * integration' s (a + h) 999

-- 2.1.3
getSecondFrom :: a -> b -> c -> b
getSecondFrom a b c = b

-- 2.1.7
multSecond = g `on` h where
  g = (*)
  h = snd

-- 2.1.9
on3 :: (b -> b -> b -> c) -> (a -> b) -> a -> a -> a -> c
on3 op f x y z = op (f x) (f y) (f z)

-- 2.2.3
doItYourself = f . g . h where
  f = logBase 2
  g = (^ 3)
  h = max 42

-- 2.3.7
class Printable a where
  toString :: a -> String

instance Printable Bool where
  toString True  = "true"
  toString False = "false"

instance Printable () where
  toString _ = "unit type"

-- 2.3.9
instance (Printable a, Printable b) => Printable (a, b) where
  toString (a, b) = '(' : toString a ++ "," ++ toString b ++ ")"

-- 2.4.3
class KnownToGork a where
  stomp :: a -> a
  doesEnrageGork :: a -> Bool

class KnownToMork a where
  stab :: a -> a
  doesEnrageMork :: a -> Bool

class (KnownToGork a, KnownToMork a) => KnownToGorkAndMork a where
  stompOrStab :: a -> a
  stompOrStab x | doesEnrageMork x && doesEnrageGork x = (stomp . stab) x
                | doesEnrageMork x = stomp x
                | doesEnrageGork x = stab x
                | otherwise = x
-- 2.4.5
ip a b c d = show a ++ show b ++ show c ++ show d
a = 127.2
b = 24.1
c = 20.1
d = 2

-- 2.4.7
class (Enum a, Eq a, Bounded a) => SafeEnum a where
  ssucc :: a -> a
  ssucc x | x == maxBound = minBound
          | otherwise = succ x
  spred :: a -> a
  spred x | x == minBound = maxBound
          | otherwise = pred x

instance SafeEnum Bool

-- 2.4.9
avg' :: Int -> Int -> Int -> Double
avg' a b c = let
    x = toInteger a
    y = toInteger b
    z = toInteger c
    s = fromInteger (x + y + z)
  in s / 3.0

-- 3.1.3
addTwoElements :: a -> a -> [a] -> [a]
addTwoElements x y = (x :) . (y :)

-- 3.1.4
nTimes:: a -> Int -> [a]
nTimes _ 0 = []
nTimes v n = v : (nTimes v (n - 1))

-- 3.1.8
oddsOnly :: Integral a => [a] -> [a]
oddsOnly [] = []
oddsOnly (x : xs) | odd x = x : oddsOnly xs
                  | otherwise = oddsOnly xs

-- 3.1.10
isPalindrome :: Eq a => [a] -> Bool
isPalindrome x = x == (reverse x)

-- 3.1.12
sum3 :: Num a => [a] -> [a] -> [a] -> [a]
sum3 xs ys zs = xs `sum2` ys `sum2` zs
  where
    sum2 (x : xs) (y : ys) = (x + y) : sum2 xs ys
    sum2 []       ys       = ys
    sum2 xs       []       = xs

-- 3.1.13
groupElems :: Eq a => [a] -> [[a]]
groupElems []                        = []
groupElems [x]                       = [[x]]
groupElems (x1 : x2 : xs) | x1 == x2 =
                              let (y : ys) = groupElems (x2 : xs)
                              in (x1 : y) : ys
                          | x1 /= x2 = [x1] : groupElems (x2 : xs)

-- 3.2.3
readDigits :: String -> (String, String)
readDigits = span isDigit

-- 3.2.4
filterDisj :: (a -> Bool) -> (a -> Bool) -> [a] -> [a]
filterDisj p1 p2 = filter (\x -> p1 x || p2 x)

-- 3.2.5
qsort :: Ord a => [a] -> [a]
qsort []       = []
qsort (x : xs) =
  let
    l = filter (< x) xs
    r = filter (>= x) xs
  in qsort l ++ x : qsort r

-- 3.2.7
squares'n'cubes :: Num a => [a] -> [a]
squares'n'cubes = concatMap (\x -> [x ^ 2, x ^ 3])

-- 3.2.8
perms :: [a] -> [[a]]
perms []       = [[]]
perms [x]      = [[x]]
perms (x : xs) = concat $ map (insertEverywhere x) $ perms xs
  where
    insertEverywhere :: a -> [a] -> [[a]]
    insertEverywhere x []           = [[x]]
    insertEverywhere x ys'@(y : ys) = (x : ys') : (map (y :) $ insertEverywhere x ys)

-- 3.2.10
delAllUpper :: String -> String
delAllUpper = unwords . (filter $ not . all isUpper) . words

-- 3.2.12
max3 :: Ord a => [a] -> [a] -> [a] -> [a]
max3 = zipWith3 (\x y z -> x `max` y `max` z)

-- 3.3.3
fibStream :: [Integer]
fibStream = zipWith (+) (0 : fibStream) (0 : 1 : fibStream)

-- 3.3.5
repeat' = iterate repeatHelper
repeatHelper = id

-- 3.3.7
data Odd = Odd Integer
  deriving (Eq, Show)

instance Enum Odd where
  succ (Odd x) = Odd (x + 2)
  pred (Odd x) = Odd (x - 2)
  toEnum x = Odd (toInteger x)
  fromEnum (Odd x) = fromInteger x
  enumFrom x = x : enumFrom (succ x)
  enumFromThen x'@(Odd x) y'@(Odd y)
    = x' : enumFromThen y' (Odd (y + (y - x)))
  enumFromTo x'@(Odd x) y'@(Odd y)
    | x > y     = []
    | x == y    = [x']
    | otherwise = x' : enumFromTo (succ x') y'
  enumFromThenTo x'@(Odd x) y'@(Odd y) z'@(Odd z)
    | x == y && y == z                     = enumFrom x'
    | x <= y && y <= z || x >= y && y >= z = x' : enumFromThenTo y' (Odd (y + (y - x))) z'
    | x <= min y z || x >= max y z         = [x']
    | otherwise                            = []

-- 3.3.9
coins = [2, 3, 7]
change 0 = [[]]
change n = concat [map (x : ) $ change $ n - x | x <- coins, x <= n]

-- 3.4.3
concatList :: [[a]] -> [a]
concatList = foldr (++) []

-- 3.4.5
lengthList :: [a] -> Int
lengthList = foldr (\_ a -> 1 + a) 0

-- 3.4.6
sumOdd :: [Integer] -> Integer
sumOdd = foldr addOdd 0
  where
    addOdd x a | odd x     = x + a
    addOdd _ a | otherwise = a

-- 3.5.8
meanList :: [Double] -> Double
meanList = (\(s,l) -> s / l) . foldr (\x (s,l) -> (s+x,l+1)) (0,0)

-- 3.5.9, 3.5.10
evenOnly :: [a] -> [a]
evenOnly = fst . foldr (\z ~(xs, ys) -> (ys, z : xs)) ([], [])

-- 3.6.3
lastElem :: [a] -> a
lastElem = foldl1 $ flip const

-- 3.6.10
revRange :: (Char,Char) -> [Char]
revRange = unfoldr addHigh
  where
    addHigh (l,h) | l > h     = Nothing
                  | otherwise = Just (h, (l, pred h))

-- 4.1.5
data Color = Red | Green | Blue

instance Show Color where
  show Red = "Red"
  show Green = "Green"
  show Blue = "Blue"

-- 4.1.7
charToInt :: Char -> Int
charToInt c | isDigit c = fromEnum c - fromEnum '0'

-- 4.1.8
stringToColor :: String -> Color
stringToColor "Red" = Red
stringToColor "Blue" = Blue
stringToColor "Green" = Green

-- 4.1.11
data LogLevel = Error | Warning | Info deriving Show

cmp :: LogLevel -> LogLevel -> Ordering
cmp Error   Error   = EQ
cmp Warning Warning = EQ
cmp Info    Info    = EQ
cmp Error   _       = GT
cmp _       Info    = GT
cmp _       _       = LT

-- 4.1.13
data Result = Fail | Success
type SomeData = Int

doSomeWork :: SomeData -> (Result,Int)
doSomeWork 0 = (Success,0)
doSomeWork n = (Fail,n)

processData :: SomeData -> String
processData d =
  case doSomeWork d of
    (Success,_) -> "Success"
    (Fail,n)    -> "Fail: " ++ show n

-- 4.2.3
data Point' = Point' Double Double

origin :: Point'
origin = Point' 0.0 0.0

distanceToOrigin :: Point' -> Double
distanceToOrigin (Point' x y) = sqrt (x ^ 2 + y ^ 2)

distance :: Point' -> Point' -> Double
distance (Point' x1 y1) (Point' x2 y2) = sqrt ((x1 - x2) ^ 2 + (y1 - y2) ^ 2)

-- 4.2.5
data Shape = Circle Double | Rectangle Double Double

area :: Shape -> Double
area (Circle r)      = pi * r ^ 2
area (Rectangle a b) = a * b

-- 4.2.6
data Result' = Fail' Int | Success'

instance Show Result' where
    show (Fail' n)  = "Fail: " ++ show n
    show (Success') = "Success"

doSomeWork' :: SomeData -> Result'
doSomeWork' d =
  case doSomeWork d of
    (Fail, n)    -> Fail' n
    (Success, _) -> Success'

-- 4.2.8
square :: Double -> Shape
square a = Rectangle a a

isSquare :: Shape -> Bool
isSquare (Circle _)                  = False
isSquare (Rectangle a b) | a == b    = True
                         | otherwise = False

-- 4.2.9
data Bit = Zero' | One' deriving (Show, Eq)
data Sign = Minus' | Plus' deriving (Show, Eq)
data Z = Z Sign [Bit] deriving (Show, Eq)

toDigit :: Bit -> Integer
toDigit Zero' = 0
toDigit One'  = 1

toBit :: Integer -> Bit
toBit 0 = Zero'
toBit 1 = One'

toNumber :: [Bit] -> Integer
toNumber xs = foldr (\(d, b) a -> a + (toDigit b) * 2 ^ d) 0 $ zip [0..] xs

toBits :: Integer -> [Bit]
toBits 0 = [Zero']
toBits 1 = [One']
toBits n = (toBit $ n `mod` 2) : toBits (n `div` 2)

add' :: Z -> Z -> Z
add' (Z s xs) (Z s' ys) | s == s' = Z s $ toBits (toNumber xs + toNumber ys)
add' (Z Plus' xs) (Z Minus' ys)     = 
  let diff = toNumber xs - toNumber ys
  in if diff >= 0
     then Z Plus' $ toBits diff
     else Z Minus' $ toBits $ (-diff)
add' x y                          = add' y x

mul' :: Z -> Z -> Z
mul' (Z s1 xs) (Z s2 ys) = Z (getSign s1 s2) $ toBits (toNumber xs * toNumber ys)
  where
    getSign x y | x == y    = Plus'
                | otherwise = Minus'

-- 4.3.3
timeToString :: UTCTime -> String
timeToString = formatTime defaultTimeLocale "%a %d %T"

data LogEntry = LogEntry { timestamp :: UTCTime, logLevel :: LogLevel, message :: String }

logLevelToString :: LogLevel -> String
logLevelToString level = show level

logEntryToString :: LogEntry -> String
logEntryToString entry =
  (entry & timestamp & timeToString) ++ ": " ++
  (entry & logLevel & logLevelToString) ++ ": " ++
  (entry & message)

-- 4.3.5
data Person = Person { firstName :: String, lastName :: String, age :: Int } deriving Show

updateLastName :: Person -> Person -> Person
updateLastName p1 p2 = p2 {lastName = lastName p1} 

-- 4.3.8
abbrFirstName :: Person -> Person
abbrFirstName p@Person{ firstName = fn } | length fn < 2 = p
                                         | otherwise     = p { firstName = head fn : "." }

-- 4.4.3
data Coord a = Coord a a deriving Show

distance' :: Coord Double -> Coord Double -> Double
distance' (Coord x1 y1) (Coord x2 y2) = sqrt ((x1 - x2) ^ 2 + (y1 - y2) ^ 2)

manhDistance :: Coord Int -> Coord Int -> Int
manhDistance (Coord x1 y1) (Coord x2 y2) = abs (x1 - x2) + abs (y1 - y2)

-- 4.4.4
getCenter :: Double -> Coord Int -> Coord Double
getCenter a (Coord x y) = Coord (a * fromIntegral x + a / 2)  (a * fromIntegral y + a / 2)

getCell :: Double -> Coord Double -> Coord Int
getCell a (Coord x y) = Coord (floor $ x / a) (floor $ y / a)

-- 4.4.6
findDigit :: [Char] -> Maybe Char
findDigit = foldl f Nothing where
  f Nothing x | isDigit x = Just x
              | otherwise = Nothing
  f x       _             = x

-- 4.4.7
findDigitOrX :: [Char] -> Char
findDigitOrX str =
  case findDigit str of
    Just d -> d
    _      -> 'X'

-- 4.4.8
maybeToList :: Maybe a -> [a]
maybeToList (Just x) = [x]
maybeToList _        = [] 

listToMaybe :: [a] -> Maybe a
listToMaybe (x : xs) = Just x
listToMaybe _        = Nothing

-- 4.4.9
data Error = ParsingError | IncompleteDataError | IncorrectDataError String deriving Show

splitOn :: Char -> String -> [String]
splitOn c str = splitOn' c [] [] str where
  splitOn' :: Char -> [String] -> String -> String -> [String]
  splitOn' c res word []       | null word = reverse res
                               | otherwise = reverse (reverse word : res)
  splitOn' c res word (x : xs) | x /= c    = splitOn' c res (x : word) xs
                               | null word = splitOn' c res word xs
                               | otherwise = splitOn' c (reverse word : res) [] xs

trim :: String -> String
trim str = reverse $ dropWhile isSpace $ reverse $ dropWhile isSpace str

has :: Char -> String -> Bool
has c = any (== c)

parsePerson :: String -> Either Error Person
parsePerson str =
  let
    lines = splitOn '\n' str
  in
    if not $ all (has '=') lines then Left ParsingError
    else
      let
        splitOnFirst :: Char -> String -> [String]
        splitOnFirst c = (\(xs, y : ys) -> [xs, ys]) . span (/= c)

        labels = map (map trim . splitOnFirst '=') lines
      in
        if any ((== 0) . length . head) labels then Left ParsingError
        else
          if any ((== 0) . length . head . tail) labels then Left ParsingError
          else
            let
              findTailByHead :: String -> [[String]] -> Maybe String
              findTailByHead h ((x : xs) : _) | x == h  = Just $ head xs
              findTailByHead h (xs : xss)               = findTailByHead h xss
              findTailByHead _ _                        = Nothing

              fn' = findTailByHead "firstName" labels
              ln' = findTailByHead "lastName" labels
              a' = findTailByHead "age" labels
            in
              case (fn', ln', a') of
                (Just fn, Just ln, Just a) ->
                  if not $ all isNumber a then Left $ IncorrectDataError a
                  else Right $ Person { firstName = fn, lastName = ln, age = read a :: Int } 
                _                          -> Left IncompleteDataError

-- 4.4.12
eitherToMaybe :: Either a b -> Maybe a
eitherToMaybe (Left a) = Just a
eitherToMaybe (Right _) = Nothing

-- 4.5.3
data List a = Nil | Cons a (List a)

fromList' :: List a -> [a]
fromList' Nil          = []
fromList' (Cons x xs) = x : fromList' xs

toList :: [a] -> List a
toList []       = Nil
toList (x : xs) = Cons x $ toList xs

-- 4.5.4
data Nat = Zero | Suc Nat deriving Show

fromNat :: Nat -> Integer
fromNat Zero = 0
fromNat (Suc n) = fromNat n + 1

toNat :: Integer -> Nat
toNat 0 = Zero
toNat n = Suc $ toNat (n - 1)

add :: Nat -> Nat -> Nat
add x y = toNat (fromNat x + fromNat y)

mul :: Nat -> Nat -> Nat
mul x y = toNat (fromNat x * fromNat y)

fac :: Nat -> Nat
fac Zero = Suc Zero
fac x    = mul x $ fac $ toNat $ fromNat x - 1

-- 4.5.5
data Tree'' a = Leaf'' a | Node (Tree'' a) (Tree'' a)

height :: Tree'' a -> Int
height (Leaf'' _)   = 0
height (Node x y) = 1 + max (height x) (height y)

size :: Tree'' a -> Int
size (Leaf'' _)   = 1
size (Node x y) = 1 + size x + size y

-- 4.5.6
avg :: Tree'' Int -> Int
avg t =
    let (c,s) = go t
    in s `div` c
  where
    go :: Tree'' Int -> (Int,Int)
    go (Leaf'' x) = (1, x)
    go (Node x y) = let
        (c1, s1) = go x
        (c2, s2) = go y
      in (c1 + c2, s1 + s2)

-- 4.5.8
infixl 6 :+:
infixl 7 :*:
data Expr = Val Int | Expr :+: Expr | Expr :*: Expr
  deriving (Show, Eq)

isMonom :: Expr -> Bool
isMonom (e1 :+: e2) = False
isMonom (e1 :*: e2) = isMonom e1 && isMonom e2
isMonom e           = True

isMonomSum :: Expr -> Bool
isMonomSum (e1 :+: e2)             = isMonomSum e1 && isMonomSum e2
isMonomSum e           | isMonom e = True
                       | otherwise = False

expand :: Expr -> Expr
expand e                   | isMonomSum e    = e
expand ((e1 :+: e2) :*: e)                   = expand (expand (expand e1 :*: expand e) :+: expand (expand e2 :*: expand e))
expand (e :*: (e1 :+: e2))                   = expand (expand (expand e :*: expand e1) :+: expand (expand e :*: expand e2))
expand (e1 :+: e2)                           = expand (expand e1 :+: expand e2)
expand (e1 :*: e2)                           = expand (expand e1 :*: expand e2)
expand e                                     = e

-- 4.6.7
newtype Xor = Xor { getXor :: Bool }
  deriving (Eq,Show)

instance Monoid Xor where
  mempty = Xor False
  
  mappend (Xor x) (Xor y) | x == y    = Xor False
                          | otherwise = Xor True

-- 4.6.9
newtype Maybe' a = Maybe' { getMaybe :: Maybe a }
  deriving (Eq,Show)

instance Monoid a => Monoid (Maybe' a) where
  mempty = Maybe' (Just mempty)
  
  mappend (Maybe' Nothing) _ = Maybe' Nothing
  mappend _ (Maybe' Nothing) = Maybe' Nothing
  mappend (Maybe' x) (Maybe' y) = Maybe' (x `mappend` y)

-- 4.6.10
class MapLike m where
  empty :: m k v
  lookup' :: Ord k => k -> m k v -> Maybe v
  insert' :: Ord k => k -> v -> m k v -> m k v
  delete' :: Ord k => k -> m k v -> m k v
  fromList :: Ord k => [(k,v)] -> m k v
  fromList [] = empty
  fromList ((k,v):xs) = insert' k v (fromList xs)

newtype ListMap k v = ListMap { getListMap :: [(k,v)] }
  deriving (Eq,Show)

instance MapLike ListMap where
  empty = ListMap []

  lookup' key = foldl takeKey Nothing . getListMap where
    takeKey x'@(Just x) _                = x'
    takeKey _          (k,v) | key == k  = Just v
                             | otherwise = Nothing
                        
  insert' k v = ListMap . ((k, v) :) . getListMap . delete' k

  delete' key = ListMap . foldl skip [] . getListMap where
    skip acc kv@(k, v) | key == k  = acc
                       | otherwise = kv : acc

-- 4.6.12
newtype ArrowMap k v = ArrowMap { getArrowMap :: k -> Maybe v }

instance MapLike ArrowMap where
  empty = ArrowMap (const Nothing)

  lookup' k am = (getArrowMap am) k
                        
  insert' key v (ArrowMap am) = ArrowMap am' where
    am' k | key == k  = Just v
          | otherwise = am k

  delete' key (ArrowMap am) = ArrowMap am' where
    am' k | key == k  = Nothing
          | otherwise = am k

-- 5.1.4
data Point3D a = Point3D a a a deriving Show

instance Functor Point3D where
  fmap f (Point3D x y z) = Point3D (f x) (f y) (f z)

--5.1.5
data GeomPrimitive a = Point (Point3D a) | LineSegment (Point3D a) (Point3D a)

instance Functor GeomPrimitive where
  fmap f (Point x)         = Point (fmap f x)
  fmap f (LineSegment x y) = LineSegment (fmap f x) (fmap f y)

--5.1.7
data Tree' a = Leaf' (Maybe a) | Branch (Tree' a) (Maybe a) (Tree' a) deriving Show

instance Functor Tree' where
  fmap f (Leaf' x)       = Leaf' (fmap f x)
  fmap f (Branch l x r) = Branch (fmap f l) (fmap f x) (fmap f r) 

--5.1.9
data Entry k1 k2 v = Entry (k1, k2) v deriving Show
data Map k1 k2 v = Map [Entry k1 k2 v] deriving Show

instance Functor (Entry k1 k2) where
  fmap f (Entry k v) = Entry k (f v)

instance Functor (Map k1 k2) where
  fmap f (Map xs) = Map (fmap (fmap f) xs)

-- 5.2.3
data Log a = Log [String] a deriving Show

toLogger :: (a -> b) -> String -> (a -> Log b)
toLogger f msg = \x -> Log [msg] (f x)

execLoggers :: a -> (a -> Log b) -> (b -> Log c) -> Log c
execLoggers x f g = let
    (Log lf y) = f x
    (Log lg z) = g y
  in Log (lf ++ lg) z

-- 5.2.5
returnLog :: a -> Log a
returnLog x = Log [] x

-- 5.2.7
bindLog :: Log a -> (a -> Log b) -> Log b
bindLog (Log l x) f = let (Log l' y) = f x in Log (l ++ l') y

-- 5.2.8
instance Functor Log where
  fmap = liftM

instance Applicative Log where
  pure = return
  (<*>) = ap

instance Monad Log where
  return = returnLog
  (>>=) = bindLog

execLoggersList :: a -> [a -> Log a] -> Log a
execLoggersList x = foldl (>>=) (return x)

-- 5.3.3
data SomeType a = SomeType

instance Applicative SomeType where
  pure = undefined
  (<*>) = undefined

instance Monad SomeType where
  (>>=) = undefined
  return = undefined

instance Functor SomeType where
  fmap f x = x >>= return . f

-- 5.4.4
data Token = Number Int | Plus | Minus | LeftBrace | RightBrace 
  deriving (Eq, Show)

asToken :: String -> Maybe Token
asToken str | all isDigit str = Just $ Number $ read str
            | otherwise       = lookup str $ zip ["+","-","(",")"] [Plus,Minus,LeftBrace,RightBrace]

tokenize :: String -> Maybe [Token]
tokenize = foldr tryAddToken (return []) . words where
  tryAddToken w mtl = do
    t <- asToken w
    tl <- mtl
    return (t : tl)

-- 5.4.6
data Board = Board

nextPositions :: Board -> [Board]
nextPositions _ = []

nextPositionsN :: Board -> Int -> (Board -> Bool) -> [Board]
nextPositionsN b 0 p | p b       = [b]
nextPositionsN b n p | n < 0     = []
                     | otherwise = do
  nb <- nextPositions b
  nextPositionsN nb (n - 1) p

-- 5.4.8
pythagoreanTriple :: Int -> [(Int, Int, Int)]
pythagoreanTriple x = do
  c <- [1 .. x]
  b <- [1 .. x]
  a <- [1 .. b - 1]
  True <- return (a ^ 2 + b ^ 2 == c ^ 2)
  return (a, b, c)

-- 5.5.3
main'' :: IO ()
main'' = do
  putStrLn "What is your name?"
  putStr "Name: "
  name <- getLine
  if length name > 0
    then putStrLn $ "Hi, " ++ name ++ "!"
    else main''

-- 5.5.8
main' :: IO ()
main' = do
  putStr "Substring: "
  substring <- getLine
  if null substring
    then putStrLn "Canceled"
    else do
      fileNames <- getDirectoryContents "."
      let filteredFileNames = filter (substring `isInfixOf`) fileNames
      let mRemove fileName = do { putStrLn $ "Removing file: " ++ fileName; removeFile fileName }
      mapM_ mRemove filteredFileNames

-- 5.6.8
data Reader r a = Reader { runReader :: (r -> a) }

instance Functor (Reader r) where
  fmap = undefined

instance Applicative (Reader r) where
  pure = undefined
  (<*>) = undefined

instance Monad (Reader r) where
  return x = Reader $ \_ -> x
  m >>= k  = Reader $ \r -> runReader (k (runReader m r)) r

ask :: Reader r r
ask = Reader id

asks :: (r -> a) -> Reader r a
asks = Reader

local :: (r -> r) -> Reader r a -> Reader r a
local f m = Reader $ \e -> runReader m (f e)

local' :: (r -> r') -> Reader r' a -> Reader r a
local' f m = Reader $ \e -> runReader m (f e)

-- 5.6.9
type User = String
type Password = String
type UsersTable = [(User, Password)]

usersWithBadPasswords :: Reader UsersTable [User]
usersWithBadPasswords = do
  asks $ map fst . (filter $ (== "123456") . snd)
  
-- 5.7.3
newtype Writer w a = Writer { runWriter :: (a, w) }

instance Functor (Writer w) where
  fmap = undefined

instance Applicative (Writer w) where
  pure = undefined
  (<*>) = undefined

instance Monoid w => Monad (Writer w) where
  return x = Writer (x, mempty)
  m >>= k  = let
      (x, w1) = runWriter m
      (y, w2) = runWriter (k x)
    in Writer (y, w1 `mappend` w2)

evalWriter :: Writer w a -> a
evalWriter = fst . runWriter

tell :: w -> Writer w ()
tell w = Writer ((), w)

-- 5.7.6
type Shopping' = Writer (Sum Integer) ()

execWriter :: Writer w a -> w
execWriter = snd . runWriter

purchase' :: String -> Integer -> Shopping'
purchase' _ cost = tell (Sum cost)

total' :: Shopping' -> Integer
total' s = case execWriter s of (Sum x) -> x

-- 5.7.7
type Shopping = Writer ([String], Sum Integer) ()

purchase :: String -> Integer -> Shopping
purchase item cost = tell ([item], Sum cost)

total :: Shopping -> Integer
total s = case execWriter s of (_, Sum x) -> x

items :: Shopping -> [String]
items = fst . execWriter

-- 5.8.6
newtype State s a = State { runState :: s -> (a, s) }

instance Functor (State s) where
  fmap = liftM

instance Applicative (State s) where
  pure = return
  (<*>) = ap

instance Monad (State s) where
  return x = State $ \s -> (x, s)
  m >>= k  = State $ \s -> let
      (x, s') = runState m s
      m' = k x
    in runState m' s'

execState :: State s a -> s -> s
execState m s = snd (runState m s)

evalState :: State s a -> s -> a
evalState m s = fst (runState m s)

get :: State s s
get = State $ \s -> (s, s)

put :: s -> State s ()
put s = State $ \_ -> ((), s)

readerToState :: Reader r a -> State r a
readerToState (Reader f) = State $ \s -> (f s, s)

-- 5.8.7
writerToState :: Monoid w => Writer w a -> State w a
writerToState (Writer (x, w)) = State $ \_ -> (x, w)

-- 5.8.9
instance Monoid Integer where
  mempty = 0
  mappend = (+)

fibStep :: State (Integer, Integer) ()
fibStep = do
  (p, c) <- get
  put (c, p + c)

execStateN :: Int -> State s a -> s -> s
execStateN n m = execState (replicateM n m)

fib :: Int -> Integer
fib n = fst $ execStateN n fibStep (0, 1)

-- 5.8.10
data Tree a = Leaf a | Fork (Tree a) a (Tree a) deriving Show

modify :: (s -> s) ->  State s s
modify f = do
  s <- get
  put (f s)
  return s

numberTree :: Tree () -> Tree Integer
numberTree tree = evalState (numberTree' tree) 1 where
  numberTree' :: Tree () -> State Integer (Tree Integer)
  numberTree' (Leaf _) = do
    n <- modify (+ 1)
    return (Leaf n)
  numberTree' (Fork l _ r) = do
    l' <- numberTree' l
    n <- modify (+ 1)
    r' <- numberTree' r
    return (Fork l' n r')
