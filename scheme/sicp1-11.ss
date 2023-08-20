;; SICP 1.11

;; Recursive version
(define (f-recursive n)
  (if (< n 3)
      n
      (+
       (f (- n 1))
       (* 2 (f (- n 2)))
       (* 3 (f (- n 3))))))

;; Iterative version
(define (f n)
  (define (f-iter a b c count)
    (if (<= count 1)
        b
        (f-iter (+ a (* 2 b) (* 3 c)) a b (- count 1))))
  (f-iter 2 1 0 n))
