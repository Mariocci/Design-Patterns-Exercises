public class Main {
    public static void main(String[] args) {
        Sheet s = new Sheet(5, 5);

        s.set("A1", "2");
        s.set("A2", "5");
        s.set("A3", "A1+A2");
        s.set("B1", "A1+A3");
        s.set("E2", "A2+B1");
        s.set("D3", "A1+A3+B5");
        System.out.println(s);

        System.out.println("======================");

        s.set("A1", "4");
        s.set("A4", "A1+A3");
        System.out.println(s);
        System.out.println("======================");

        try {
            s.set("A1", "A3");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }
}
