(defun factor (x)
  (let ((ans 1))
    (dotimes (i x)
      (setf ans (* ans (+ i 1))))
    ans))

(defun solve ()
  (format t "~a~%" (factor (read))))

(defun main ()
  (let ((all (read)))
    (dotimes (i all)
      (solve))))

(main)
