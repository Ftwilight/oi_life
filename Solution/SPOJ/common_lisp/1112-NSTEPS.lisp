(declaim (optimize (speed 3)))

(defun get-ans (x y)
  (declare (fixnum x y))
  (cond ((= x y) (if (evenp x)
                    (* x 2)
                    (+ (* (- x 1) 2) 1)))
        ((and (= x (+ y 2)) (>= x 2)) (if (evenp x)
                          (* (- x 1) 2)
                          (+ (* (- x 2) 2) 1)))
        (t "No Number")))

(defun main ()
  (let ((cnt (read)))
    (do ((i 1 (+ i 1)))
        ((> i cnt) 't)
      (format t "~A~%" (get-ans (read) (read))))))

(main)
