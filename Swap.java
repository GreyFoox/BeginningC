public class Swap {
    public static void main(String[] args) {
        // 创建一个包含两个整数的对象
        Pair pair = new Pair(1, 2);
        // 调用 swap 方法并传递对象引用
        swap(pair);
        // 打印交换后的结果
        System.out.println(pair.a + " " + pair.b);
    }

    // swap 方法接收 Pair 对象的引用
    public static void swap(Pair pair) {
        // 交换对象中的两个整数值
        int temp = pair.a;
        pair.a = pair.b;
        pair.b = temp;
    }
}

// 定义一个包含两个整数的类
class Pair {
    int a;
    int b;

    Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
}
