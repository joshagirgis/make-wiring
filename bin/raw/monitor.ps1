"Close Window or press Ctrl+C to Quit"
"Available Ports:"
[System.IO.Ports.SerialPort]::getportnames()
$COM=Read-Host -Prompt 'Input your COM port'
$baud=Read-Host -Prompt 'Input baud rate'
$port= new-Object System.IO.Ports.SerialPort $COM,$baud,None,8,one
$port.open()
While ($true){
$port.ReadLine()
}
$port.Close()