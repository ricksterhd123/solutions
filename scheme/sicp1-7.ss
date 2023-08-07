;; 1.8 sicp

;; Calculate cube root
(define (cbrt x)
  (define (square x)
    (* x x))
  (define (improve guess x)
    (/ (+ (/ x (square guess)) (* 2 guess)) 3))
  (define (good-enough? guess last-guess)
    (< (abs (- guess last-guess)) 0.00000001))
  (define (cbrt-iter guess last-guess x)
    (if (good-enough? guess last-guess)
        guess
        (cbrt-iter (improve guess x)
                   guess
                   x)))
  (cbrt-iter 1.0 0 x))
