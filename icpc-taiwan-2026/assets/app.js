// Shared behaviour for the ICPC Taiwan 2026 study pages.
(function () {
  const PAGES = [
    { file: "index.html", short: "Roadmap", title: "Roadmap" },
    { file: "01-foundations.html", short: "01 พื้นฐาน", title: "C++ & พื้นฐานการแข่ง" },
    { file: "02-search-greedy.html", short: "02 Search/Greedy", title: "Sorting, Binary Search, Greedy" },
    { file: "03-dp.html", short: "03 DP", title: "Dynamic Programming" },
    { file: "04-graphs.html", short: "04 Graph", title: "Graph Algorithms" },
    { file: "05-trees-ds.html", short: "05 Tree/DS", title: "Trees & Data Structures" },
    { file: "06-math.html", short: "06 Math", title: "Math & Number Theory" },
    { file: "07-strings.html", short: "07 String", title: "Strings" },
    { file: "08-geometry.html", short: "08 Geometry", title: "Computational Geometry" },
    { file: "09-contest.html", short: "09 Contest", title: "กลยุทธ์ทีม & Mock Contest" },
  ];
  const KEY = "icpc26:";
  const store = {
    get(k) { try { return localStorage.getItem(KEY + k); } catch (e) { return null; } },
    set(k, v) { try { localStorage.setItem(KEY + k, v); } catch (e) {} },
    del(k) { try { localStorage.removeItem(KEY + k); } catch (e) {} },
  };

  // ---- theme ----
  const savedTheme = store.get("theme");
  if (savedTheme) document.documentElement.dataset.theme = savedTheme;

  const page = document.body.dataset.page || "index.html";

  // ---- top bar ----
  const bar = document.createElement("header");
  bar.className = "topbar";
  bar.innerHTML =
    '<div class="inner"><a class="home" href="index.html">ICPC Taiwan 2026 Prep</a><nav>' +
    PAGES.slice(1).map(p => `<a href="${p.file}" class="${p.file === page ? "active" : ""}">${p.short}</a>`).join("") +
    '</nav><button class="theme-btn" type="button">ธีม</button></div>';
  document.body.prepend(bar);
  bar.querySelector(".theme-btn").addEventListener("click", () => {
    const cur = document.documentElement.dataset.theme ||
      (matchMedia("(prefers-color-scheme: dark)").matches ? "dark" : "light");
    const next = cur === "dark" ? "light" : "dark";
    document.documentElement.dataset.theme = next;
    store.set("theme", next);
  });

  // ---- problem checklists ----
  const items = [...document.querySelectorAll(".problems li")];
  items.forEach((li, i) => {
    const a = li.querySelector("a");
    if (a && a.dataset.cses) {
      a.href = "https://cses.fi/problemset/task/" + a.dataset.cses;
      a.insertAdjacentHTML("afterend", ' <span class="tag">CSES</span>');
    } else if (a && a.dataset.cf) {
      const [c, idx] = a.dataset.cf.split("/");
      a.href = `https://codeforces.com/problemset/problem/${c}/${idx}`;
      a.insertAdjacentHTML("afterend", ` <span class="tag">CF ${c}${idx}</span>`);
    } else if (a && a.dataset.ac) {
      const [contest, task] = a.dataset.ac.split("/");
      a.href = `https://atcoder.jp/contests/${contest}/tasks/${task}`;
      a.insertAdjacentHTML("afterend", ` <span class="tag">AtCoder</span>`);
    }
    if (a) { a.target = "_blank"; a.rel = "noopener"; }
    if (li.classList.contains("must")) li.querySelector("a")?.insertAdjacentHTML("afterend", ' <span class="tag must">ต้องทำ</span>');
    if (li.classList.contains("hard")) li.querySelector("a")?.insertAdjacentHTML("afterend", ' <span class="tag hard">ท้าทาย</span>');
    if (li.classList.contains("repo")) li.querySelector("a")?.insertAdjacentHTML("afterend", ' <span class="tag repo">มีใน repo แล้ว</span>');

    const id = page + "|" + (li.dataset.id || (a ? a.getAttribute("href") : "item" + i));
    const wrap = document.createElement("div");
    while (li.firstChild) wrap.appendChild(li.firstChild);
    const cb = document.createElement("input");
    cb.type = "checkbox";
    cb.setAttribute("aria-label", "ทำข้อนี้แล้ว");
    const saved = store.get("p:" + id);
    cb.checked = saved === null ? li.classList.contains("repo") : saved === "1";
    li.classList.toggle("checked", cb.checked);
    cb.addEventListener("change", () => {
      store.set("p:" + id, cb.checked ? "1" : "0");
      li.classList.toggle("checked", cb.checked);
      updateProgress();
    });
    li.append(cb, wrap);
    li._cb = cb;
  });

  function updateProgress() {
    if (!items.length) return;
    const done = items.filter(li => li._cb.checked).length;
    store.set("total:" + page, String(items.length));
    store.set("done:" + page, String(done));
    const el = document.getElementById("page-progress");
    if (el) {
      el.innerHTML = `<span>ความคืบหน้าหน้านี้</span><div class="progress"><span style="width:${(100 * done / items.length).toFixed(1)}%"></span></div><span>${done}/${items.length}</span>`;
    }
  }
  updateProgress();

  // ---- index cards: aggregate progress ----
  let allDone = 0, allTotal = 0, seen = 0;
  document.querySelectorAll(".card[data-page]").forEach(card => {
    const p = card.dataset.page;
    const total = +store.get("total:" + p) || 0, done = +store.get("done:" + p) || 0;
    const out = card.querySelector(".count");
    if (!out) return;
    if (total) {
      seen++; allDone += done; allTotal += total;
      out.innerHTML = `<div class="progress"><span style="width:${(100 * done / total).toFixed(1)}%"></span></div>${done}/${total} ข้อ`;
    } else {
      out.textContent = "ยังไม่ได้เปิดหน้านี้";
    }
  });
  const overall = document.getElementById("overall-progress");
  if (overall) {
    overall.innerHTML = allTotal
      ? `<span>รวมทุกหน้าที่เปิดแล้ว (${seen}/${PAGES.length - 1})</span><div class="progress"><span style="width:${(100 * allDone / allTotal).toFixed(1)}%"></span></div><span>${allDone}/${allTotal}</span>`
      : "<span>เปิดแต่ละหน้าอย่างน้อยหนึ่งครั้ง แล้วความคืบหน้ารวมจะแสดงที่นี่</span>";
  }

  // ---- code blocks: copy button + highlight ----
  document.querySelectorAll("pre > code").forEach(code => {
    if (!code.className) code.className = "language-cpp";
    const btn = document.createElement("button");
    btn.className = "copy-btn"; btn.type = "button"; btn.textContent = "copy";
    btn.addEventListener("click", async () => {
      try { await navigator.clipboard.writeText(code.innerText); btn.textContent = "copied"; }
      catch (e) { btn.textContent = "เลือกข้อความเอง"; }
      setTimeout(() => (btn.textContent = "copy"), 1400);
    });
    code.parentElement.appendChild(btn);
  });
  if (window.hljs) { try { window.hljs.highlightAll(); } catch (e) {} }

  // ---- prev / next pager ----
  const idx = PAGES.findIndex(p => p.file === page);
  const main = document.querySelector("main");
  if (main && idx > 0) {
    const prev = PAGES[idx - 1], next = PAGES[idx + 1];
    const pager = document.createElement("div");
    pager.className = "pager";
    pager.innerHTML =
      `<a href="${prev.file}">← ${prev.title}</a>` + (next ? `<a href="${next.file}">${next.title} →</a>` : "<span></span>");
    main.appendChild(pager);
  }
})();

// re-apply the URL hash after the top bar and highlighting change the layout
if (location.hash) {
  try { document.querySelector(decodeURIComponent(location.hash))?.scrollIntoView(); } catch (e) {}
}
