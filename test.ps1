Get-Date -Format "HH:mm"
$x = ((Get-Date).hour)
$y = ((Get-Date).minute)
if($x -eq 9){
  Start-Process "https://1ctinus.me/wotw"
  if($y -eq 35){
Start-Process "https://1ctinus.me"
  }
}else {
Start-Process "https://1ctinus.me/no"
}
pause
