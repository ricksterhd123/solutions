;; the little schemer atom definition
;; (atom? (quote ())) => #f
;(define atom?
;  (lambda (x)
;    (and (not (pair? x)) (not (null? x)))))

;; clear screen
(define clear
  (let ((clear-iter
      (lambda (n)
        (if (> n 0)
            (begin
              (display "\n")
              (clear-iter (- n 1)))
            (display "")))))
    (lambda () (clear-iter 100))))


