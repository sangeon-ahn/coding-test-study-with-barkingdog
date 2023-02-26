import java.util.*;

/**
 * d[a][b] = 알고력이 a, 코딩력이 b 에 도달하는 최저 시간
 * d[a][b] = min(d[a-1][b] + 1, d[a][b-1] + 1, {d[a-pro[i][a]][b-pro[i][b]] + pro[i][c], ...})
 */
class Solution {
    static final int INF = (int) 1e9;
    int[][] d = new int[451][451];

    public int solution(int alp, int cop, int[][] problems) {
        //모든 문제를 풀기 위해 필요한 알고력, 코딩력 구하기
        int[] maxAlpCop = getMaxAlpCop(problems);

        //바로 모든 문제를 풀 수 있는 경우
        if (maxAlpCop[0] <= alp && maxAlpCop[1] <= cop) return 0;

        //d 초기화
        for (int i = 0; i < d.length; i++) {
            Arrays.fill(d[i], INF);
        }
        d[alp][cop] = 0;

        //점화식 계산
        for (int a = alp; a < d.length; a++) {
            for (int b = cop; b < d[a].length; b++) {
                if (a == alp && b == cop) continue;

                //문제를 풀지 않고 알고력과 코딩력을 높이는 경우
                if (a-1 >= 0) {
                    d[a][b] = Math.min(d[a][b], d[a-1][b] + 1);
                }
                if (b-1 >= 0) {
                    d[a][b] = Math.min(d[a][b], d[a][b-1] + 1);
                }

                //문제를 풀어 알고력과 코딩력을 높이는 경우
                updateByProblems(a, b, problems);
            }
        }

        return getAnswer(maxAlpCop[0], maxAlpCop[1]);
    }

    private void updateByProblems(int a, int b, int[][] problems) {
        for (int i = 0; i < problems.length; i++) {
            int aLimit = problems[i][0];
            int bLimit = problems[i][1];
            int problemA = problems[i][2];
            int problemB = problems[i][3];
            int cost = problems[i][4];

            if (a - problemA < aLimit) continue; // 알고력이 낮아 해당 문제를 풀수없는 경우
            if (b - problemB < bLimit) continue; // 코딩력이 낮아 해당 문제를 풀수없는 경우

            d[a][b] = Math.min(d[a][b], d[a-problemA][b-problemB] + cost);
        }
    }

    private int[] getMaxAlpCop(int[][] problems) {
        int maxAlp = 0;
        int maxCop = 0;
        for (int[] problem : problems) {
            maxAlp = Math.max(maxAlp, problem[0]);
            maxCop = Math.max(maxCop, problem[1]);
        }

        return new int[] {maxAlp, maxCop};
    }

    private int getAnswer(int maxAlp, int maxCop) {
        int answer = INF;

        for (int a = maxAlp; a < d.length; a++) {
            for (int b = maxCop; b < d[a].length; b++) {
                answer = Math.min(answer, d[a][b]);
            }
        }

        return answer;
    }
}