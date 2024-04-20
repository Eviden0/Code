

import java.io.UnsupportedEncodingException;

import sun.misc.BASE64Decoder;

/**
 * base64 编码、解码util
 *
 * @author lifq
 * @date 2015-3-4 上午09:23:33
 */
public class ab{
    /**
     * 将 s 进行 BASE64 编码
     *
     * @return String
     * @author lifq
     * @date 2015-3-4 上午09:24:02
     */
    public static String encode(String s) {
        if (s == null)
            return null;
        String res = "";
        try {
            res = new sun.misc.BASE64Encoder().encode(s.getBytes("GBK"));
        } catch (UnsupportedEncodingException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return res;
    }

    /**
     * 将 BASE64 编码的字符串 s 进行解码
     *
     * @return String
     * @author lifq
     * @date 2015-3-4 上午09:24:26
     */
    public static String decode(String s) {
        if (s == null)
            return null;
        BASE64Decoder decoder = new BASE64Decoder();
        try {
            byte[] b = decoder.decodeBuffer(s);
            return new String(b,"GBK");
        } catch (Exception e) {
            return null;
        }
    }
    /**
     *
     * @return void
     * @author lifq
     * @date 2015-3-4 上午09:23:17
     */
    public static void main(String[] args) {
        System.out.println(ab.encode("哈哈"));
        System.out.println(ab.decode("eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpZCI6ImIyNTc2MDgxMTZiZjQ0NmNiZGI1MTk1ZWIwZTU2NGZmIiwiZXhwIjoxNzE0MTQwNjQ5LCJrZXkiOiI4NmRhMjVmN2JjNTE0Zjg5ODRmZWY4OGE1Njc1NmI0MyIsInVzZXJuYW1lIjoiMjAyMjA1NTAxOTE5In0.QEPR4ZCCKbuipLgIWQL9oOZuHOR3yEbrZ22RV_9RJ5M"));

    }

}