#!/system/bin/sh

if [ $# -ne 1 ]; then
	echo "please set the action: 'start' or 'stop'"
	exit
fi

action=$1
tmp_file="/data/cpu_stat_start.tmp"

function stof()
{
	st=$1
	len=${#st}
	fl=0.0

	if [ $len -eq 1 ];then
		fl="0."$st
	else
		ca=`expr $len - 1`
		fl=${st:0:$ca}"."${st:(-1)}
	fi
	echo $fl
}

function calculate()
{
	begin=$1

	OLD_IFS="$IFS"
	IFS=" "
	begin_arr=($begin)
	cpu=${begin_arr[0]}
	end=`cat /proc/stat | grep $cpu | head -1`
	end_arr=($end)
	IFS="$OLD_IFS"

	user=`expr ${end_arr[1]} - ${begin_arr[1]}`
	ni=`expr ${end_arr[2]} - ${begin_arr[2]}`
	sys=`expr ${end_arr[3]} - ${begin_arr[3]}`
	idle=`expr ${end_arr[4]} - ${begin_arr[4]}`
	iw=`expr ${end_arr[5]} - ${begin_arr[5]}`
	irq=`expr ${end_arr[6]} - ${begin_arr[6]}`
	softirq=`expr ${end_arr[7]} - ${begin_arr[7]}`
	steal=`expr ${end_arr[8]} - ${begin_arr[8]}`

	total_cpu_time=`expr $user + $ni + $sys + $idle + $iw + $irq + $softirq + $steal`
	total_idle_time=`expr $idle + $iw`
	total_cpu_usage=`expr $total_cpu_time - $total_idle_time`
	total_cpu_percentage=`expr $total_cpu_usage \* 1000 / $total_cpu_time`

	us_p=`expr $user \* 1000 / $total_cpu_time`
	ni_p=`expr $ni \* 1000 / $total_cpu_time`
	sy_p=`expr $sys \* 1000 / $total_cpu_time`
	id_p=`expr $idle \* 1000 / $total_cpu_time`
	wa_p=`expr $iw \* 1000 / $total_cpu_time`
	ir_p=`expr $irq \* 1000 / $total_cpu_time`
	si_p=`expr $softirq \* 1000 / $total_cpu_time`
	st_p=`expr $steal \* 1000 / $total_cpu_time`



	echo -n "$cpu: `stof $total_cpu_percentage` % "
	echo -n "us: `stof $us_p` sy: `stof $sy_p` ni: `stof $ni_p` id: `stof $id_p` "
	echo "wa: `stof $wa_p` ir: `stof $ir_p` si: `stof $si_p` st: `stof $st_p`"


}



if [ "$action" == "start" ]; then
	data=`cat /proc/stat | grep cpu[0-9]`
	echo -e "$data" > $tmp_file
	echo "save /proc/stat to $tmp_file"
else
	if [ -f "$tmp_file" ]; then
		data=`cat $tmp_file`
		while read line
		do
			calculate "$line"
		done < $tmp_file
	else
		echo "please run start first!"
		exit
	fi

fi

