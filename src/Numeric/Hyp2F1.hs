module Numeric.Hyp2F1 where

hyp2f1 :: Double -> Double -> Double -> Double -> Double
hyp2f1 a b c z = realToFrac $ unsafePerformIO $
    h2f1 (realToFrac a) (realToFrac b) (realToFrac c) (realToFrac z)

foreign import ccall "hyp2f1"
    h2f1 :: CDouble -> CDouble -> CDouble -> CDouble -> IO CDouble
