# QInt

## Ý tưởng
-Bản chất thật sự của việc lưu trữ dữ liệu trong máy tính là các dòng chuỗi số 0 và 1 (hệ nhị phân) và vì vậy để lưu được dữ liệu kiểu QInt ta cũng sẽ thực hiện lưu trữ dưới dạng hệ nhị phân (tức bản chất Qint là một chuỗi nhị phân). Ta chỉ cần xây dựng hàm biến đổi dữ liệu input đầu vào sang kiểu nhị phân và truyền vào QInt:
<br> +HexToQInt: Chuyển từ hệ thập lục phân sang nhị phân và lưu vào QInt
<br> +DecToQInt: Chuyển từ hệ thập phân sang nhị phân và lưu vào QInt
<br> +BinToQInt: Lưu vào Qint
<br>
<br> -Sau đó chúng ta sẽ thực hiện các phép toán: +, -, *, /, <<, rol, …. Trên chuỗi nhị phân một cách bình thường nhờ vào kiến thức đã học và các công cụ hỗ trợ của ngôn ngữ lập trình. 
<br>
<br> -Sau khi đã thực hiện xong việc tính toán thì ta lại xuất output trở ngược ra bằng cách làm ngược lại, xây dựng hàm biến đổi dữ nhị phân sang kiểu dữ liệu mà ta muốn và xuất ra output:
<br> +QIntToDec: Chuyển từ hệ nhị phân trong QInt sang hệ thập phân và xuất ra output
<br> +QIntToBin: Dữ nguyên hệ nhị phân và xuất ra output
<br> +QIntToHex: Chuyển từ hệ nhị phân trong QInt sang hệ thập lục phân và xuất ra output

## Phạm vi
Miền dấu – là miền có thể biểu diễn, miền dấu + là miền không thể biểu diễn


+++++-2127 -------------------------------- 0 --------------------------------- 2127 – 1+++++
<br>

Miền biểu diễn ở hệ thập phân:
<br>
<br>Từ: -170141183460469231731687303715884105728 ~ -1.7e38
<br>
<br>Đến: 170141183460469231731687303715884105727 ~1.7e38
