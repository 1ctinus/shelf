function St($in, $am = 2){
switch ($in){
"w"{$in = "White"}
"db"{$in = "DarkBlue"}
"c"{$in = "Cyan"}
"r"{$in = "Red"}
"y"{$in = "Yellow"}
"g"{$in = "Green"}
$null{$in="White"}
}
Write-Host $(" " * $am) -BackgroundColor $in -NoNewline;
}
function bk ($le){
Write-Host $(" " * $le) -NoNewline;
}
function en{
Write-Host " ";
}
function long {
bk(6);st 'r';st 'y';st 'c';st 'db';
}
<#1#>bk(12);st 'db';en
<#2#>bk(10);st 'c';st 'db';en
<#3#>bk(8);st;st 'c';st 'db';en
<#4#>bk 4;st 'db';st 'w' 4;st 'c';st 'db';en
<#5#>bk(2);st 'g';st 'y' 6;st 'c';st 'db';en
<#6#>st 'r' 8;st 'y';st 'c';st 'db';bk 16; st;en;
<#7#>long; bk 16; st;en;
<#8#>long;bk 4;st 'w' 6; bk 6; st;bk 14; st 'w' 6;bk 4; st; bk 14; st 'w' 6; bk 4; st 'w' 4; bk 2; st 'w' 4;en
<#9#>long;bk(2);st;bk 6;st;bk 2;st 'w' 6;bk 10; st;bk 6; st; bk 2; st; bk 12; st; bk 6; st; bk 4; st; bk 4; st;en
<#10#>long;bk(2);st;bk 12;st; bk 4; st 'w' 6;bk 2; st;bk 10; st; bk 2; st 'w' 4; bk 4; st; bk 6; st; bk 6; st; bk 4; st;en
<#11#>long;bk(2);st;bk 12;st;bk 14; st 'w' 6;bk 4; st 'w' 4; bk 4; st 'w' 2;bk 2; st; bk 2; st 'w' 4; bk 8; st; bk 4; st;en
<#12#>long;bk(2);st;bk 12;st;bk 20;st; bk 2; st; bk 6; st; bk 2; st 'w' 4; bk 12; st; bk 4; st;en
<#13#>long;bk(2);st;bk 6;st;bk 4; st;bk 12;st;bk 6; st; bk 2; st; bk 6; st; bk 4; st; bk 6; st; bk 4; st; bk 4; st;en
<#14#>bk(6);st 'r';st 'y';st 'g';bk 6;st 'w' 6;bk 6;st;bk 14; st 'w' 6;bk 4; st; bk 6; st; bk 6; st 'w' 6; bk 6; st 'w' 4; bk 2;  st 'w' 4;en
<#15#>bk(6);st 'r' 4;en
pause
