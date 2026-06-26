# 💰 Persistent Financial Ledger (C++)

## 📌 Overview
A version-controlled financial ledger built using a **Persistent Segment Tree** in C++.  
Each transaction creates a new version, allowing historical queries and auditability.

---

## 🚀 Features
- Versioned ledger system
- O(log n) updates and queries
- Historical state queries
- Fraud detection (spike, percentage, z-score)
- Immutable version history

---

## ⚙️ Operations
- `txn from to amount` → transfer money & create new version  
- `query version l r` → range sum query on a version  
- `status` → number of versions  

---

## 🧠 Concepts Used
- Persistent Segment Tree  
- Version Control System  
- Range Queries (Segment tree)  
- Fraud Detection Logic  

---

## 📊 Complexity
- Build: O(n)
- Update: O(log n)  
- Query: O(log n)  
- Space: O(n + q log n)  

---

## 📌 Notations Used

| Symbol | Meaning |
|--------|--------|
| n | Number of accounts (array size) |
| q | Number of transactions / versions |
| log n | Height of segment tree |
| Vᵢ | i-th version of ledger |
| Node | Segment tree node storing sum |
| rootᵢ | Root of i-th version |
| l, r | Range in segment tree |
| from, to | Accounts involved in transaction |
| amount | Money transferred |

---
