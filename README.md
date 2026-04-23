# 🧾 Time-Travel Financial Ledger System

## 🚀 Overview
Built a version-controlled financial ledger in C++ using persistent data structures.  
Each transaction creates a new version, allowing queries on past states, comparison between versions, and basic fraud detection.

---

## ✨ Features
- Versioned transactions (immutable history)
- Time-travel queries on any past version
- Fraud detection based on balance changes
- Efficient memory usage using node sharing

---

## 🔤 Notation

- n = number of accounts  
- ai = initial balances  
- q = number of transactions  
- from → to → amount = transfer money  
- k = number of queries  
- version = which version to query  
- l, r = range of accounts

---

## ⚙️ Complexity
- Update: O(log n)
- Query: O(log n)
- Space: O(n + q log n)
