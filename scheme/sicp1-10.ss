;; Ackermanns function
(define (A x y)
  (cond ((= y 0) 0)
        ((= x 0) (* 2 y))
        ((= y 1) 2)
        (else (A (- x 1)
                 (A x (- y 1))))))

;; (f n) => 2n
(define (f n) (A 0 n))
;; (f n) => 2^n
(define (g n) (A 1 n))
;; (h n) => ??? - this grows very eratically...
(define (h n) (A 2 n))
;; (k n) => 5n^2
(define (k n) (* 5 n n))

(display (A 1 10))
(display "\n")
(display (A 2 4))
(display "\n")
(display (A 3 3))
(display "\n")
