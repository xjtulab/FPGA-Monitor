#!/usr/bin/python3
import socket
import sys

#pid name %cpu %mem used_mem
class ProcessInfo:

    def __init__(self, line: str):
        splited_list = list(line.split())

        self.pid = int(splited_list[0])
        self.name = splited_list[1]
        self.cpu_usage = float(splited_list[2])
        self.mem_usage = float(splited_list[3])
        self.used_mem = int(splited_list[4])


    def __str__(self) -> str:
        return str.format("pid: {} name: {} cpu_ussage: {}% mem_usage: {}% used_mem: {}",
            self.pid, self.name, self.cpu_usage, self.mem_usage, self.used_mem)


class Status:
    def __init__(self) -> None:
        self.infos = []

    def read_buf(self, buf: str):
        self.infos.clear()
        for line in buf.split('\n'):
            if len(line) == 0:
                continue
            self.infos.append(ProcessInfo(line))

    
    def show_status(self):
        i = 1
        for info in self.infos:
            print('{}. {}'.format(i, str(info)))
            i = i + 1

        #clear infos          


if __name__ == '__main__':

    status = Status()
    serv = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    serv.bind(('127.0.0.1', 9999))

    print('Status report server at 127.0.0.1: 9999 through UDP:')

    while True:
        data, addr = serv.recvfrom(1024)
        buf = str(data, encoding='utf-8')

        if (len(buf) == 0):
            print('There is no information of processes')
            continue

        print('recv buf: [{}]'.format(buf))

        status.read_buf(buf)
        status.show_status()

