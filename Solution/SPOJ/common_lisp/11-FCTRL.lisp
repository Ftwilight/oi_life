(defun calc (n ans)
  (declare (fixnum n ans))
  (if (> n 0)
      (let ((temp (floor (/ n 5))))
        (calc temp (+ ans temp)))
      ans))

(defun main ()
  (do ((i (read) (- i 1)))
      ((= i 0) t)
    (format t "~A~%" (calc (read) 0))))

(main)
