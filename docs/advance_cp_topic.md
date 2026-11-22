# Advanced CP Topics — Study & Teaching Guide

Nov 21, 2026 · @Heng Suphachock

## How to use this guide

Work each topic in three passes: read one primary resource, solve the warm-up and core problems, then try one challenge before moving on. Each section ends with a teaching order and the pitfalls students hit most, so it doubles as a lesson plan.

**Problem marks**

- ***Must-do*** (bold italic): the problem that best teaches *recognizing* the technique. Do these first.
- `*` Should-do: good reinforcement; do if time allows.
- Unmarked: optional extra.

**Tiers:** Warm-up = the bare technique, recognizable from the statement · Core = you must model the problem before the technique appears · Challenge = technique combined with something else, contest-level.

**Suggested order across topics** (each builds on the one before):

1. Segment tree + lazy propagation — you already have a working implementation; harden it first.
2. Modular arithmetic, CRT, floor-sum — math toolkit used everywhere else.
3. Bitmask DP, SOS DP — DP over states, small n.
4. DP on trees, rerooting — DP over structure.
5. Convex hull trick, Li Chao tree — speeding up DP transitions.
6. Alien's trick (WQS binary search) — removes a "exactly k" dimension; usually paired with CHT.

## 1. Modular arithmetic, CRT, floor-sum

**Core idea.** Work in Z/mZ so huge counts stay small: add, subtract and multiply freely, and divide only by multiplying with an inverse (exists iff gcd(a, m) = 1). CRT glues congruences x ≡ aᵢ (mod mᵢ) into one congruence mod lcm(mᵢ), merging two at a time with extended Euclid. Floor-sum evaluates the sum below in O(log m) by a Euclid-like recursion, which counts lattice points under a line.

```latex
\text{floor\_sum}(n,m,a,b)=\sum_{i=0}^{n-1}\left\lfloor \frac{a\,i+b}{m} \right\rfloor
```

**Recognize it when:** "print the answer modulo 998244353 / 10⁹+7" (modular + combinatorics); several periodic conditions must hold at once, or remainders by different numbers are given (CRT); you need to count integer points under a line, or sum ⌊(ai+b)/m⌋ over a long range (floor-sum).

**Complexity:** fast power O(log e); inverse by Fermat O(log p) or ext. Euclid O(log m); factorials + inverse factorials O(n) precompute, O(1) per nCr; CRT O(k log M) for k congruences; floor-sum O(log m).

**Resources**

- [CP-Algorithms: Binary Exponentiation](https://cp-algorithms.com/algebra/binary-exp.html) · [Modular Inverse](https://cp-algorithms.com/algebra/module-inverse.html) · [Extended Euclid](https://cp-algorithms.com/algebra/extended-euclid-algorithm.html) · [Linear Congruence Equation](https://cp-algorithms.com/algebra/linear_congruence_equation.html)
- [CP-Algorithms: Chinese Remainder Theorem](https://cp-algorithms.com/algebra/chinese-remainder-theorem.html) — includes the non-coprime case.
- [USACO Guide: Modular Arithmetic](https://usaco.guide/gold/modular) and [Combinatorics](https://usaco.guide/gold/combo) — best first read, with practice lists.
- [AtCoder Library: math](https://atcoder.github.io/ac-library/production/document_en/math.html) — reference specs for `pow_mod`, `inv_mod`, `crt`, `floor_sum`; read the constraints to learn the overflow cases.

**Problems**

| Tier | Problem | Practices | Mark |
| --- | --- | --- | --- |
| Warm-up | [CSES Exponentiation](https://cses.fi/problemset/task/1095) | Fast power mod p | \* |
| Warm-up | [CSES Exponentiation II](https://cses.fi/problemset/task/1712) | a^(b^c): reduce the exponent mod p−1 (Fermat) | ***Must*** |
| Warm-up | [CSES Binomial Coefficients](https://cses.fi/problemset/task/1079) | Factorial + inverse factorial tables | ***Must*** |
| Core | [CSES Christmas Party](https://cses.fi/problemset/task/1717) | Derive the derangement recurrence, then compute mod p | \* |
| Core | [CSES Sum of Divisors](https://cses.fi/problemset/task/1082) | Swap the sum order, group equal n/i blocks; mod 2-inverse | ***Must*** |
| Core | [CF 687B Remainders Game](https://codeforces.com/problemset/problem/687/B) | CRT reasoning: x mod k is known iff k divides lcm(cᵢ) | ***Must*** |
| Core | [CF 710D Two Arithmetic Progressions](https://codeforces.com/problemset/problem/710/D) | Model as two congruences, solve with ext. Euclid, count in a range | \* |
| Core | [ACL Practice C: Floor Sum](https://atcoder.jp/contests/practice2/tasks/practice2_c) | Implement floor-sum and test it | \* |
| Core | [Library Checker: Sum of Floor of Linear](https://judge.yosupo.jp/problem/sum_of_floor_of_linear) | Same, stronger tests | |
| Challenge | [yukicoder 187 中華風 (Hard)](https://yukicoder.me/problems/no/187) | CRT with non-coprime moduli and an inconsistency check | \* |
| Challenge | [ABC372 G: Ax + By < C](https://atcoder.jp/contests/abc372/tasks/abc372_g) | Turn a lattice-point count into floor-sum | ***Must*** |
| Challenge | [CF 338D GCD Table](https://codeforces.com/problemset/problem/338/D) | Generalized CRT with lcm overflow, then verify the candidate | |

**Teaching order:** mod rules and fast power → inverses (Fermat, then ext. Euclid) → nCr tables → linear congruence ax ≡ b → CRT (coprime, then general) → floor-sum as "counting lattice points".

**Common pitfalls**

- `a * b % m` overflows when m > ~3·10⁹; use `__int128` or keep m below 2³¹.
- `%` of a negative number is negative in C++: write `((x % m) + m) % m`.
- Fermat's inverse needs a prime modulus; for composite m use ext. Euclid and check gcd = 1.
- Exponent reduction uses mod (p − 1), not mod p.
- CRT with non-coprime moduli: check a₁ ≡ a₂ (mod gcd) or report no solution; lcm can overflow.
- Integer division truncates toward zero, so `floor` of negatives is wrong; floor-sum also needs a, b normalized into [0, m).

## 2. DP on trees, rerooting

**Core idea.** Root the tree; dp[v] summarizes v's subtree and is built from its children's dp in post-order. Rerooting gets the answer for *every* root in O(n) total. First compute down[v] (subtree of v). Then push up[v] (everything outside v's subtree) from parent to child. The child's value is "parent with this child removed", combined with the parent's own up.

**Recognize it when:** the input is a tree and the answer for a vertex depends on its subtree (counting, matching, independent sets, max path). Rerooting fits when the problem asks "for each vertex, as if it were the root" or "sum of distances to all others", or when the best root must be chosen and n is too big to try each in O(n).

**Complexity:** single-root DP O(n · cost of merge); rerooting O(n) with prefix/suffix products of children, or O(n) with inverse "remove child" when the merge is invertible. Tree knapsack with sizes is O(n²) total (the size-bound argument), not O(n³).

**Resources**

- [USACO Guide: DP on Trees — Introduction](https://usaco.guide/gold/dp-trees) — start here.
- [USACO Guide: DP on Trees — Solving for All Roots](https://usaco.guide/gold/all-roots) — rerooting with worked CSES examples.
- [Codeforces: DP on Trees Tutorial](https://codeforces.com/blog/entry/20935) — classic problem walkthroughs.
- [Codeforces: The Ultimate Reroot Template](https://codeforces.com/blog/entry/124286) — a generic rerooting abstraction; read after you have written rerooting by hand twice.

**Problems**

| Tier | Problem | Practices | Mark |
| --- | --- | --- | --- |
| Warm-up | [CSES Subordinates](https://cses.fi/problemset/task/1674) | Subtree sizes, post-order | \* |
| Warm-up | [CSES Tree Diameter](https://cses.fi/problemset/task/1131) | Best two child depths per vertex | \* |
| Warm-up | [EDPC P: Independent Set](https://atcoder.jp/contests/dp/tasks/dp_p) | Two-state dp[v][color] | ***Must*** |
| Core | [CSES Tree Matching](https://cses.fi/problemset/task/1130) | dp[v][is v matched]; greedy vs DP | ***Must*** |
| Core | [CSES Tree Distances I](https://cses.fi/problemset/task/1132) | First rerooting: farthest vertex from every node | \* |
| Core | [CSES Tree Distances II](https://cses.fi/problemset/task/1133) | Canonical rerooting: sum of distances, shift by subtree size | ***Must*** |
| Core | [CF 1092F Tree with Maximum Cost](https://codeforces.com/problemset/problem/1092/F) | Same rerooting with weights; spot it from the cost formula | \* |
| Core | [CF 219D Choosing Capital for Treeland](https://codeforces.com/problemset/problem/219/D) | Model edge directions as 0/1 costs, then reroot | ***Must*** |
| Core | [CF 1324F Maximum White Subtree](https://codeforces.com/problemset/problem/1324/F) | Reroot where children contribute max(0, dp) | \* |
| Core | [CF 1187E Tree Painting](https://codeforces.com/problemset/problem/1187/E) | Realize the score is a sum of subtree sizes, then reroot | ***Must*** |
| Challenge | [EDPC V: Subtree](https://atcoder.jp/contests/dp/tasks/dp_v) | Rerooting with a non-invertible merge (mod M not prime): prefix/suffix products | ***Must*** |
| Challenge | [ABC160 F: Distributing Integers](https://atcoder.jp/contests/abc160/tasks/abc160_f) | Rerooting + counting topological orders (links to Topic 1) | \* |
| Challenge | [ABC222 F: Expensive Expense](https://atcoder.jp/contests/abc222/tasks/abc222_f) | Reroot a max-distance with vertex costs | \* |
| Challenge | [CF 815C Karen and Supermarket](https://codeforces.com/problemset/problem/815/C) | Tree knapsack, O(n²) merging by sizes | |

**Teaching order:** subtree sizes → two-state DP (independent set, matching) → diameter → rerooting on sum of distances (draw the "move root across one edge" picture) → rerooting with prefix/suffix for non-invertible merges → tree knapsack.

**Common pitfalls**

- Recursive DFS on a path of 2·10⁵ vertices can overflow the stack; use an iterative order (BFS order reversed) or raise the stack.
- In rerooting, up[child] must exclude the child's own contribution; forgetting this double-counts.
- "Divide out the child" fails when values can be 0 or the modulus is not prime; use prefix/suffix instead.
- Sum of distances needs `long long` (up to ~n²/2).
- Tree knapsack loops must be bounded by current subtree sizes, or it becomes O(n³).

## 3. Bitmask DP, SOS DP

**Core idea.** Bitmask DP: when n ≤ ~20, the state is the *set* of items used so far, stored as an integer mask (often plus "last item"). SOS DP: compute F[mask] = Σ A[sub] over all submasks at once by adding one bit dimension at a time, like a prefix sum in n dimensions. The same loop run the other way gives superset sums, and its inverse gives Möbius / inclusion–exclusion.

```latex
F[\text{mask}] = \sum_{\text{sub} \subseteq \text{mask}} A[\text{sub}]
```

**Recognize it when:** n ≤ 20 (sometimes ≤ 24) and the answer depends on *which* items were chosen, not just how many: orderings (TSP, Hamiltonian paths), assignments, partitions into groups. SOS fits when values are ≤ 2²⁰ and the condition is about AND/OR/submask relations ("a & b = 0", "x | y = x", "AND of a subset is 0").

**Complexity:** dp[mask][v] over orderings O(2ⁿ n²); iterating all submasks of all masks O(3ⁿ); SOS O(n · 2ⁿ) instead of O(3ⁿ); broken-profile tiling O(m · n · 2ⁿ).

**Resources**

- [USACO Guide: Bitmask DP](https://usaco.guide/gold/dp-bitmasks) — core read with graded problems.
- [CP-Algorithms: Enumerating submasks of a bitmask](https://cp-algorithms.com/algebra/all-submasks.html) — the `s = (s - 1) & m` loop and the 3ⁿ proof.
- [Codeforces: SOS Dynamic Programming [Tutorial]](https://codeforces.com/blog/entry/45223) — the standard SOS explanation and problem list.
- [USACO Guide: Sum over Subsets DP](https://usaco.guide/plat/dp-sos) — SOS with more practice problems.

**Problems**

| Tier | Problem | Practices | Mark |
| --- | --- | --- | --- |
| Warm-up | [EDPC O: Matching](https://atcoder.jp/contests/dp/tasks/dp_o) | dp over mask, row = popcount(mask) | ***Must*** |
| Warm-up | [CSES Hamiltonian Flights](https://cses.fi/problemset/task/1690) | dp[mask][last]; loop order and memory | \* |
| Core | [CSES Elevator Rides](https://cses.fi/problemset/task/1653) | State = (rides, weight in last ride) pair per mask | ***Must*** |
| Core | [EDPC U: Grouping](https://atcoder.jp/contests/dp/tasks/dp_u) | Partition into groups by submask enumeration, O(3ⁿ) | ***Must*** |
| Core | [CF 11D A Simple Task](https://codeforces.com/problemset/problem/11/D) | Count cycles: fix the lowest vertex to avoid double counting | \* |
| Core | [CSES Counting Tilings](https://cses.fi/problemset/task/2181) | Broken-profile DP (mask = column frontier) | \* |
| Core | [CSES SOS Bit Problem](https://cses.fi/problemset/task/1654) | Subset sums, superset sums, and complement in one problem | ***Must*** |
| Core | [CF 165E Compatible Numbers](https://codeforces.com/problemset/problem/165/E) | a & b = 0 ⇔ b ⊆ ~a; SOS storing a witness | ***Must*** |
| Challenge | [CF 449D Jzzhu and Numbers](https://codeforces.com/problemset/problem/449/D) | Superset counts + inclusion–exclusion with 2^cnt mod p | \* |
| Challenge | [CF 383E Vowels](https://codeforces.com/problemset/problem/383/E) | Count via complement ("no vowel in set") + SOS | |

**Teaching order:** bit tricks (set, test, iterate bits) → TSP-style dp[mask][v] → dp on mask alone (matching, elevator) → submask enumeration and the 3ⁿ bound → SOS as an n-dimensional prefix sum → superset sums, complement tricks, inclusion–exclusion.

**Common pitfalls**

- Memory: 2²⁰ × 20 ints is 80 MB; check before declaring `dp[1<<n][n]`.
- Use `1LL << k` when k can reach 31+; operator precedence: `a & b == 0` means `a & (b == 0)`.
- In SOS, the bit loop must be the *outer* loop; swapping loops double-counts.
- The submask loop `for (s = m; s; s = (s - 1) & m)` skips s = 0; handle it separately.
- Counting cycles or partitions: fix a canonical element (lowest bit) to avoid counting rotations or orders twice.

## 4. Segment tree + lazy propagation

**Core idea.** Each node stores a summary (a monoid: an associative merge with an identity) of its range. Lazy propagation stores a pending update (a tag) on a node and pushes it to the children only when they are visited. It needs three rules: apply a tag to a node's summary, compose two tags, and merge two summaries. Most of the skill is *designing the node*: what to store so that merge and apply are O(1).

**Recognize it when:** an array gets range updates and range queries mixed online, n, q ≈ 2·10⁵. Also when a query is "first index where …" (descend the tree), or when the answer for a range can be built from the answers of two halves plus a little extra info (max subarray, inversions in a 0/1 array).

**Complexity:** build O(n); each update or query O(log n); memory 4n nodes (or 2·next power of two).

**Resources**

- [CP-Algorithms: Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html) — full reference, including lazy, descending and persistent variants.
- [USACO Guide: Range Update Range Query](https://usaco.guide/plat/RURQ) — lazy propagation with practice problems.
- [AtCoder Library: lazy_segtree](https://atcoder.github.io/ac-library/production/document_en/lazysegtree.html) — the cleanest statement of the S / F / op / mapping / composition contract; teach the abstraction from it.
- [Codeforces: Efficient and easy segment trees](https://codeforces.com/blog/entry/18051) — bottom-up iterative trees, including lazy.
- [Codeforces EDU courses](https://codeforces.com/edu/courses) — the ITMO Academy pilot course has two Segment Tree lessons with video and graded steps (login required).

**Problems**

| Tier | Problem | Practices | Mark |
| --- | --- | --- | --- |
| Warm-up | [CSES Range Update Queries](https://cses.fi/problemset/task/1651) | Range add, point query (lazy or difference array) | \* |
| Warm-up | [CSES Range Updates and Sums](https://cses.fi/problemset/task/1735) | Two tag types (add, assign) and their composition order | ***Must*** |
| Warm-up | [CF 52C Circular RMQ](https://codeforces.com/problemset/problem/52/C) | Range add / range min with wrap-around split | \* |
| Core | [CSES Hotel Queries](https://cses.fi/problemset/task/1143) | Descend the tree to find the first index with value ≥ x | ***Must*** |
| Core | [CSES Subarray Sum Queries](https://cses.fi/problemset/task/1190) | Node design: (sum, prefix, suffix, best) | ***Must*** |
| Core | [CSES Polynomial Queries](https://cses.fi/problemset/task/1736) | Lazy arithmetic progression: tag = (first term, step) | \* |
| Core | [ACL Practice K: Range Affine Range Sum](https://atcoder.jp/contests/practice2/tasks/practice2_k) | Affine tags x → bx + c, composition mod p | \* |
| Core | [ACL Practice L: Lazy Segment Tree](https://atcoder.jp/contests/practice2/tasks/practice2_l) | Flip 0/1, count inversions: node = (zeros, ones, inv) | ***Must*** |
| Core | [CF 242E XOR on Segment](https://codeforces.com/problemset/problem/242/E) | Per-bit counts make XOR-update + sum-query work | \* |
| Challenge | [CF 1114F Please, another Queries on Array?](https://codeforces.com/problemset/problem/1114/F) | Lazy product + OR of a prime bitmask for φ (Topics 1 + 3) | ***Must*** |
| Challenge | [Library Checker: Range Affine Range Sum](https://judge.yosupo.jp/problem/range_affine_range_sum) | Speed test for your template | |

**Teaching order:** point update / range query → range add with lazy → two tag types and composition order → node design (max subarray, 0/1 inversions) → descending search → the ACL abstraction (S, F, op, mapping, composition) so students stop rewriting the tree.

**Common pitfalls**

- Forgetting `push` before recursing into children, or before a partial query.
- Wrong composition order: "assign then add" ≠ "add then assign"; an assign must clear older add tags.
- Sum tags need the segment length: adding v to a node adds v · len to its sum.
- Array size: 4n, not 2n, for the recursive tree.
- An identity element that is wrong for the op, e.g. 0 for min, poisons merges.

## 5. Convex hull trick, Li Chao tree

**Core idea.** Many O(n²) DPs have the form below. Each earlier j is a line with slope mⱼ and intercept bⱼ, and dp[i] is the lowest line at x = xᵢ. Keep only the lower envelope of the lines. Convex hull trick (CHT) keeps the envelope in a deque, which works when slopes arrive in sorted order. A Li Chao tree is a segment tree over x where each node keeps the line that wins at its midpoint; it accepts lines and queries in any order.

```latex
dp[i] = \min_{j<i} \big( m_j \cdot x_i + b_j \big) + c_i
```

**Recognize it when:** you write an O(n²) DP whose transition has a product of a j-term and an i-term, often after expanding a square like (hᵢ − hⱼ)² or a cost like sᵢ · fⱼ. If you can rewrite the cost as "line of j evaluated at a value of i", it is CHT.

**Complexity:** monotone slopes and monotone queries: O(n) total with a deque (pointer walk); monotone slopes, arbitrary queries: O(n log n) with binary search; arbitrary order: Li Chao O(log C) per insert/query; Li Chao with line *segments*: O(log² C) per insert.

**Resources**

- [CP-Algorithms: Convex hull trick and Li Chao tree](https://cp-algorithms.com/geometry/convex_hull_trick.html) — both structures on one page, with code.
- [USACO Guide: Convex Hull Trick](https://usaco.guide/plat/convex-hull-trick) — deque CHT and Li Chao with graded problems.
- [Codeforces: Convex Hull Trick — Geometry being useful](https://codeforces.com/blog/entry/63823) — the geometric view (dot products, lower hull) that makes the trick click.

**Problems**

| Tier | Problem | Practices | Mark |
| --- | --- | --- | --- |
| Warm-up | [Library Checker: Line Add Get Min](https://judge.yosupo.jp/problem/line_add_get_min) | Implement and test a Li Chao tree | \* |
| Warm-up | [EDPC Z: Frog 3](https://atcoder.jp/contests/dp/tasks/dp_z) | Expand (hᵢ − hⱼ)² into a line; monotone CHT | ***Must*** |
| Warm-up | [CSES Monster Game I](https://cses.fi/problemset/task/2084) | Monotone slopes and queries: deque CHT | \* |
| Core | [CSES Monster Game II](https://cses.fi/problemset/task/2085) | Same DP, queries not monotone: Li Chao | ***Must*** |
| Core | [CF 319C Kalila and Dimna in the Logging Industry](https://codeforces.com/problemset/problem/319/C) | Spot the line in a cost-per-cut DP | ***Must*** |
| Core | [CF 1083E The Fair Nut and Rectangles](https://codeforces.com/problemset/problem/1083/E) | Sort first so the DP becomes CHT-friendly | ***Must*** |
| Core | [CF 631E Product Sum](https://codeforces.com/problemset/problem/631/E) | Moving one element = a line query; two directions | \* |
| Challenge | [Library Checker: Segment Add Get Min](https://judge.yosupo.jp/problem/segment_add_get_min) | Li Chao with segments, O(log²) | |
| Challenge | [CF 932F Escape Through Leaf](https://codeforces.com/problemset/problem/932/F) | Li Chao trees merged small-to-large on a tree (Topic 2) | \* |

**Teaching order:** write the O(n²) DP → rewrite the transition as lines (practice on Frog 3) → lower envelope picture → deque CHT for monotone input → Li Chao tree for arbitrary input → Li Chao on segments and merging.

**Common pitfalls**

- Min vs max: flip the sign of lines rather than rewriting the structure.
- The intersection test overflows `long long` when slope × intercept exceeds ~9·10¹⁸; use `__int128` or a cross-multiplication with care.
- Equal slopes must be handled (keep the better intercept), or the intersection divides by zero.
- Li Chao range: must cover every query x; coordinate-compress if x values are huge or negative.
- Deque CHT silently gives wrong answers if slopes are not actually monotone in the order you insert.

## 6. Alien's trick (WQS binary search / Lagrangian relaxation)

**Core idea.** Let f(k) be the best cost using *exactly* k items (segments, groups, edges). If f is convex in k, drop the k dimension. Charge a penalty λ for each item and solve the easier unconstrained problem g(λ), recording how many items its optimum used. Binary search λ until that count is k; then f(k) = g(λ) − λ·k. Geometrically, λ is the slope of a tangent line sliding along the convex curve f.

```latex
g(\lambda) = \min_{k'} \big( f(k') + \lambda k' \big), \qquad f(k) = g(\lambda^{*}) - \lambda^{*} k
```

**Recognize it when:** a DP has an extra "exactly k / at most k" dimension that makes it O(n²k) or worse, and the problem without the limit is easy (often O(n) or O(n log n), sometimes with CHT). Check convexity: each extra item helps less than the previous one (diminishing returns). If unsure, brute-force f(k) for small n and check that the differences are monotone.

**Complexity:** O(log(λ range) × cost of the unconstrained solve), e.g. O(n log C) or O(n log n log C) with CHT inside, instead of O(n·k) or O(n²k).

**Resources**

- [USACO Guide: Lagrangian Relaxation](https://usaco.guide/adv/lagrange) — the clearest walkthrough, with problems.
- [Codeforces: Incredibly beautiful DP optimization from N^3 to N log^2 N](https://codeforces.com/blog/entry/49691) — the classic blog that popularized the trick, on CF 739E; the comments discuss ties and convexity.
- Read Topic 5 first: the unconstrained subproblem is often a CHT DP.

**Problems**

| Tier | Problem | Practices | Mark |
| --- | --- | --- | --- |
| Warm-up | [ABC218 H: Red and Blue Lamps](https://atcoder.jp/contests/abc218/tasks/abc218_h) | "Exactly R red" becomes a penalty; O(n) inner DP | ***Must*** |
| Core | [CF 1279F New Year and Handle Change](https://codeforces.com/problemset/problem/1279/F) | "At most k operations" on segments; run once per letter case | ***Must*** |
| Core | [CF 958E2 Guard Duty (medium)](https://codeforces.com/problemset/problem/958/E2) | Choose k disjoint pairs; penalty on each pair | \* |
| Core | [CF 125E MST Company](https://codeforces.com/problemset/problem/125/E) | Aliens on a greedy, not a DP: MST with exactly k edges at vertex 1 | \* |
| Core | [CSES Subarray Squares](https://cses.fi/problemset/task/2086) | Split into exactly k parts: Aliens + CHT (also solvable by divide & conquer DP) | \* |
| Challenge | [CF 321E Ciel and Gondolas](https://codeforces.com/problemset/problem/321/E) | Aliens with a 2D-prefix-sum cost; compare against divide & conquer | |
| Challenge | [CF 739E Gosha is hunting](https://codeforces.com/problemset/problem/739/E) | Relax one or both of two limits (the blog problem) | \* |
| Challenge | [IOI 2016 Aliens (oj.uz)](https://oj.uz/problem/view/IOI16_aliens) | The namesake: Aliens + CHT, full ties handling | ***Must*** |

**Teaching order:** write the slow f(k) DP and plot f(k) for a sample → show convexity and the tangent-line picture → penalty λ and the unconstrained solve → binary search on integer λ → tie-breaking and recovering f(k) → combine with CHT (IOI Aliens).

**Common pitfalls**

- Ties: several k' can be optimal for the same λ. Always break ties the same way (e.g. fewest items) and compute f(k) = g(λ) − λ·k with the *target* k, not the count you got.
- Use integer λ when costs are integers; real-valued search is slower and loses precision.
- λ range must cover the largest marginal gain, often up to the max possible answer (watch for overflow in λ·k).
- "At most k" vs "exactly k": if more items never hurt, clamp λ at 0.
- Not convex → the trick gives wrong answers silently; verify on small cases.

## Link check

Every link above was opened on 21 Nov 2026 and returned the expected page title. Codeforces EDU lesson pages need a login, so the guide links to the public course list. Library Checker pages load their statement by script; their problem IDs were confirmed to resolve.
