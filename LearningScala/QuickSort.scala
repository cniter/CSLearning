object QuickSort {
    def qSort(xs: Array[Int]) {
        def swap(i: Int, j: Int) {
            val t = xs(i); xs(i) = xs(j); xs(j) = t;
        }

        def sort(l: Int, r: Int) {
            val pivot = xs(l);
            var i = l+1; var j = r;
            while (i < j) {
                while (i <= r && xs(i) < pivot) i += 1;
                while (j > l && xs(j) > pivot) j -= 1;

                if (i < j) {
                    swap(i, j);
                    i += 1;
                    j -= 1;
                }

                if (i > j) {
                    i = j;
                }
            }
            while (i > l && xs(i) > pivot) {
                i -= 1; j -= 1;
            }
            swap(i, l);

            if (l < j-1) sort(l, j-1);
            if (j+1 < r) sort(j+1, r);
        }

        sort(0, xs.length-1);
    }

    def main(args: Array[String]) {
        // val xs = Array(4, 1, 2, 5, 6);
        // val xs = Array(1, 2, 4, 4, 55, 5, 6);
        // val xs = Array(55, 6, 6);
        val xs = Array(4, 1, 5, 7,7,7,7, 2, 6);
        qSort(xs);
        println(xs.mkString(" "))
    }
}