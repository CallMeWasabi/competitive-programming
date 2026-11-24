" ===== [1] CORE : must type =====
set nocp nu rnu ru sc ls=2 so=5 wmnu
set ai cin cino=g0,:0,l1,j1
set ts=4 sw=4 sts=4 et sr
set hls is ic scs sm bs=2
set mouse=a cb=unnamedplus
set nobk nowb noswf ar
syntax on
filetype plugin indent on
colo desert
set gfn=Monospace\ 13 go-=T go-=m

" ===== [2] BUILD / RUN =====
nn <F9> :w<CR>:!g++ -std=gnu++20 -O2 -Wall -Wextra -Wshadow % -o %<<CR>
nn <F8> :w<CR>:!g++ -std=gnu++20 -g -Wall -fsanitize=address,undefined -D_GLIBCXX_DEBUG % -o %<<CR>
nn <F5> :!./%< < in<CR>
nn <F6> :!./%< < in > out && diff -bw out ans && echo OK<CR>
nn <F7> :w<CR>:vert term ./%<<CR>
tno <Esc> <C-\><C-n>

" ===== [3] AUTO BRACKETS =====
ino ( ()<Left>
ino [ []<Left>
ino { {}<Left>
ino {<CR> {<CR>}<Esc>O
ino <expr> ) getline('.')[col('.')-1]==')'?"\<Right>":")"
ino <expr> ] getline('.')[col('.')-1]==']'?"\<Right>":"]"
ino <expr> } getline('.')[col('.')-1]=='}'?"\<Right>":"}"

" ===== [4] EXTRA : optional =====
nn <C-h> <C-w>h
nn <C-j> <C-w>j
nn <C-k> <C-w>k
nn <C-l> <C-w>l
nn <Space> :noh<CR>
nn <F2> :0r ~/t.cpp<CR>
