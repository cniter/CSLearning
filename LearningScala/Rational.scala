// 主构造函数
class Rational(n: Int, d: Int) extends AnyRef {
    private def gcd(x: Int, y: Int): Int = {
        if (x == 0) y
        else if (x < 0) gcd(-x, y)
        else if (y < 0) -gcd(x, -y)
        else gcd(y % x, x)
    }
    private val g = gcd(n, d)

    // 构造函数重载（辅助构造函数）
    def this() {
        this(0, 0)  // 调用主构造函数
    }

    val number: Int = if (g != 0) n / g else 0
    val denom: Int = if (g != 0) d / g else 0

    def +(that: Rational) = new Rational(number * that.denom + that.number * denom, denom * that.denom)
    def -(that: Rational) = new Rational(number * that.denom - that.number * denom, denom * that.denom)
    def *(that: Rational) = new Rational(number * that.number, denom * that.denom)
    def /(that: Rational) = new Rational(number * that.denom, denom * that.number)

    def toNumber: Double = if (denom != 0) number.toDouble / denom else 0.0

    override def toString = "" + number + "/" + denom
}

object Rational {
    def divmod(x: Int, y: Int): (Int, Int) = (x / y, x % y)

    def main(args: Array[String]) {
        val rational = new Rational(2,1) / new Rational()
        println(rational.toNumber);
        println(rational.toString);
        
        divmod(10, 5) match {
            case (n, d) => println("quotient: " + n + ", rest: " + d)
        }

        val xy = divmod(3, 4)
        println("quotient: " + xy._1 + ", rest: " + xy._2)
    }
}