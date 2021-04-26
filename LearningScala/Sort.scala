object Sort {
    def insertSort(xsl: List[Int]): List[Int] = {
        def insert(x: Int, xs: List[Int]): List[Int] = {
            xs match {
                // case Nil => List(x)
                case List() => List(x)
                case y :: ys => if (x <= y) x :: xs else y :: insert(x, ys)
            }
        }

        if (xsl.isEmpty) Nil
        else insert(xsl.head, insertSort(xsl.tail))
    }

    def mergeSort[A](less: (A, A) => Boolean)(xs: List[A]): List[A] = {
        def merge(xs1: List[A], xs2: List[A]): List[A] = {
            if (xs1.isEmpty) xs2
            else if (xs2.isEmpty) xs1
            else if (less(xs1.head, xs2.head)) xs1.head :: merge(xs1.tail, xs2)
            else  xs2.head :: merge(xs1, xs2.tail)
        }

        val n = xs.length / 2
        if (n == 0) xs
        else merge(mergeSort(less)(xs take n), mergeSort(less)(xs drop n))
    }

    def main(args: Array[String]) {
        val xs = List(4, 1, 5, 7,7,7,7, 2, 6);
        // val xs = 3::2::1::1::Nil;
        println(xs(0), xs(1), xs(xs.length-1)) // (4,1,6)
        // val ys = insertSort(xs);
        val ys = mergeSort((x: Int, y: Int) => x > y)(xs);
        println(ys.mkString(" "))
    }
}