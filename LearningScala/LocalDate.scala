import java.util.{Date, Locale}
import java.text.DateFormat._

object LocalDate {
    def main(args: Array[String]) {
        var i = 0;
        i = 1;
        val now = new Date
        val df = getDateInstance(LONG, Locale.CHINA)
        println(df format now)
    }
}