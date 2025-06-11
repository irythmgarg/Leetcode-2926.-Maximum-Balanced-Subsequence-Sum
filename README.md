# Leetcode-2926.-Maximum-Balanced-Subsequence-Sum

# 🚀 Max Balanced Subsequence Sum

This repository provides **two approaches** to solve the problem of finding the **maximum balanced subsequence sum**:

📌 **Balanced condition**:
For a subsequence to be considered balanced:

```
nums[i] - i >= nums[j] - j   for i > j
```

## ✅ Problem Statement

Given a list of integers `nums`, find the **maximum sum** of a subsequence such that the difference `nums[i] - i` is **non-decreasing**.

---

## 🧠 Approach 1: Top-Down (Recursion + Memoization)

### 📄 File: `top_down.cpp`

### 🔍 Key Concepts:

* Uses **recursion** to explore all subsequence options
* Applies **memoization** to store and reuse results of subproblems 🧠
* Efficient for moderate input sizes

### 🧱 Logic Flow:

1. At each index, choose to:

   * ✅ **Take** the element if the balance condition is met
   * ❌ **Skip** the element
2. Track results using a `map<string, long long>` to store intermediate results

### 📦 Complexity:

* **Time**: O(n^2) in worst-case due to memo keys
* **Space**: O(n^2) for memoization map

---

## 🧠 Approach 2: Bottom-Up (Dynamic Programming)

### 📄 File: `bottom_up.cpp`

### 🔍 Key Concepts:

* Constructs solution iteratively using a DP table 📊
* More efficient for larger inputs 🏎️

### 🧱 Logic Flow:

1. Create a vector `dp` of size `n` initialized to each `nums[i]`
2. For every `i`, check all `j < i`, and if:

```
nums[i] - i >= nums[j] - j
```

Then update:

```
dp[i] = max(dp[i], nums[i] + dp[j])
```

3. Return the maximum value in `dp`

### 📦 Complexity:

* **Time**: O(n^2)
* **Space**: O(n)

---

## 🛠️ Example

```cpp
Input: nums = [3, 2, 5, 10, 7]
Output: 15
Explanation:
Choose elements: 3 (i=0), 5 (i=2), 7 (i=4)
```

---

## 📁 Files Structure

```
📦 max-balanced-subsequence-sum
├── top_down.cpp        // Top-down recursive solution
├── bottom_up.cpp       // Bottom-up DP solution
└── README.md           // 📘 This file
```

---

## 🙌 Contributions

Pull requests are welcome! For major changes, please open an issue first.

---

## 📜 License

This project is licensed under the MIT License.

---

Happy Coding! ✨💻🚀
