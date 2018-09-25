import java.util.ArrayList;
import java.util.List;

public class Solution {

    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        dfs(res, "", n, n);
        return res;
    }

    public void dfs(List<String> res, String pare, int left, int right) {
        if (left > right)
            return;
        if (left > 0)
            dfs(res, pare + "(", left-1, right);
        if (right > 0)
            dfs(res, pare + ")", left, right-1);
        if (left == 0 && right == 0)
            res.add(pare);
    }
}
