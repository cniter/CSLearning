object NQueen {
    def queens(n: Int): List[List[Int]] = {
        def isSafe(col: Int, queenList: List[Int], delta: Int): Boolean = {
            val curRow = queenList.length-1 + delta
            for (row <- List.range(0, queenList.length)) {
                val queenCol = queenList(row)
                val queenRow = queenList.length-1 - row

                if (queenCol == col) return false
                if (queenRow == curRow) return false
                if ((queenCol - col).abs == (queenRow - curRow).abs) return false
            }
            true
        }

        def placeQueens(k: Int): List[List[Int]] = {
            if (k == 0) List(List())
            else for { 
                queens <- placeQueens(k-1);
                column <- List.range(0, n);
                if isSafe(column, queens, 1) 
            } yield column :: queens
        }
        
        placeQueens(n)
    }

    def main(args: Array[String]) {
        val queenList = queens(8);
        println("queenCount: " + queenList.length)  // 92
    }
}