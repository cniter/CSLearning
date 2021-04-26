object Sqrt {
    def sqrt(x: Double): Double = {
        def sqrtIter(guess: Double, x: Double): Double = {
            if (isGoodEnough(guess, x)) guess
            else sqrtIter(improve(guess, x), x)
        }

        def improve(guess: Double, x: Double) = {
            (guess + x / guess) / 2
        }

        def isGoodEnough(guess: Double, x: Double) = (guess * guess - x).abs < 0.001    // guess * guess == x

        sqrtIter(1.0, x)
    }
}

object TailRecursion {
    def gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)

    def facorial(n: Int): Int = if (n == 0) 1 else n * facorial(n-1)

    def facorialTail(n: Int): Int = {
        def facorialIter(n: Int, res: Int): Int = {
            if (n == 0) res
            else facorialIter(n-1, res * n)
        }

        facorialIter(n, 1)
    }
}

object SimpleFunc {
    def main(args: Array[String]) {
        val sqrtValue = Sqrt.sqrt(0.01)
        println(sqrtValue)

        val gcdValue = TailRecursion.gcd(14,21)
        println(gcdValue)

        val facorialValue = TailRecursion.facorial(5)
        println(facorialValue)

        val facorialTailValue = TailRecursion.facorialTail(5)
        println(facorialTailValue)
    }
}