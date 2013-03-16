[CmdletBinding()]
param (
    [parameter(Mandatory = $false, ValueFromPipeline = $true, ValueFromPipelineByPropertyName = $true)]
    [ValidateNotNullOrEmpty()]
    [string]$Path = (Get-Location),

    [parameter(Mandatory = $false, ValueFromPipeline = $true, ValueFromPipelineByPropertyName = $true)]
    [ValidateNotNullOrEmpty()]
    [string[]]$Files = ("*.cpp", "*.h"),

    [parameter(Mandatory = $false, ValueFromPipeline = $true, ValueFromPipelineByPropertyName = $true)]
    [ValidateNotNullOrEmpty()]
    [switch]$Recurse
)

$count = 0
$nFiles = 0
# Table creation
$fileTable = New-Object System.Data.DataTable "File Summary"
$col1 = New-Object System.Data.DataColumn "FileName",      ([string])
$col2 = New-Object System.Data.DataColumn "LastWriteTime", ([string])
$col3 = New-Object System.Data.DataColumn "Length",        ([string])
$col4 = New-Object System.Data.DataColumn "Lines",         ([string])
# Add columns
$fileTable.Columns.Add($col1)
$fileTable.Columns.Add($col2)
$fileTable.Columns.Add($col3)
$fileTable.Columns.Add($col4)

if($recurse)
{
    $path = Join-Path -Path $path -ChildPath "*"
    $files | % { Get-ChildItem -Path $path -Recurse -Include $_ | % {
        $row = $fileTable.NewRow()
        $row.FileName      = $_.Name 
        $row.LastWriteTime = $_.LastWriteTime
        $row.Length        = $_.Length
        $innerCount        = 0
        Get-Content $_.FullName | % { if($_.Length -gt 0) {$innerCount++}}
        $row.Lines = $innerCount
        $count += $innerCount
        $fileTable.Rows.Add($row)
        $nFiles++
    } }
}
else 
{
    $path = Join-Path -Path $path -ChildPath "*.*"
    $files | % { Get-ChildItem -Path $path -Include $_ | % {
        $row = $fileTable.NewRow()
        $row.FileName      = $_.Name 
        $row.LastWriteTime = $_.LastWriteTime
        $row.Length        = $_.Length
        $innerCount = 0
        Get-Content $_.FullName | % { if($_.Length -gt 0) {$innerCount++}}
        $row.Lines = $innerCount
        $count += $innerCount
        $fileTable.Rows.Add($row)
        $nFiles++
    } }
}

Write-Host ">File Summary" -ForegroundColor Cyan
Write-Host "-------------" -ForegroundColor Gray
$fileTable | Sort-Object FileName | Format-Table -Auto
Write-Host "> Number of Files: ---- " -NoNewLine
Write-Host $nFiles -ForegroundColor Green
Write-Host "> Lines of Code: ------ " -NoNewLine
Write-Host $count -ForegroundColor Green
Write-Host "> Lines per File: ----- " -NoNewLine
Write-Host ("{0:N2}" -f ($count / $nFiles)) -ForegroundColor Green