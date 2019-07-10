# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    launchV2.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 15:00:03 by pvanderl          #+#    #+#              #
#    Updated: 2019/06/12 15:00:05 by pvanderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from tkinter import *
from tkinter import ttk
from tkinter import filedialog
import os

#os.popen("make fclean")
#os.popen("make")

class Root(Tk):

    global statsValues

    def __init__(self):
        self.setCurrentDir()

        super(Root, self).__init__()
        self.title("Push_swap tester")
        self.minsize(1000, 800)
        self.set_ps_zone()
        self.set_ch_zone()
        self.set_stat_zone()

    def set_ch_zone(self):
        self.ChFileFrame = ttk.LabelFrame(self, text = "Checker executable")
        self.ChFileFrame.grid(column = 1, row = 0, padx = 20, pady = 20)
        self.ChFileButton = ttk.Button(self.ChFileFrame, text = "Browse file", command = self.change_ch_file)
        self.ChFileButton.grid(column = 1, row = 1)

    def set_ps_zone(self):
        self.PSFileFrame = ttk.LabelFrame(self, text = "Push_swap executable")
        self.PSFileFrame.grid(column = 0, row = 0, padx = 20, pady = 20)
        self.PSFileButton = ttk.Button(self.PSFileFrame, text = "Browse file", command = self.change_ps_file)
        self.PSFileButton.grid(column = 1, row = 1)

    def set_stat_zone(self):
        self.StatsFrame = ttk.LabelFrame(self, text="Stats on push_swap")
        self.StatsFrame.grid(column = 0, row = 1, columnspan = 2)
        self.label = ttk.Label(self.StatsFrame, text="What kind of stats?")
        self.label.grid(column = 0, row = 0)
        self.StatType = ttk.Combobox(self.StatsFrame, state="readonly",\
        values=[x["text"] for x in statsValues])
        self.StatType.set("Choose a stat to perform")
        self.StatType.bind("<<ComboboxSelected>>", self.comboboxEvent)
        self.StatType.grid(column = 0, row = 1)

    def comboboxEvent(self, event):
        statsValues[self.StatType.current()]["visu"](self)

    def change_ps_file(self):
        self.ps_file = filedialog.askopenfilename(initialdir = self.currentDir, title="pick a file")
        self.label = ttk.Label(self.PSFileFrame, text="")
        self.label.grid(column = 1, row = 2)
        self.label.configure(text=self.ps_file)

    def change_ch_file(self):
        self.ch_file = filedialog.askopenfilename(initialdir = self.currentDir, title="pick a file")
        self.label = ttk.Label(self.ChFileFrame, text="")
        self.label.grid(column = 1, row = 2)
        self.label.configure(text=self.ch_file)

    def setCurrentDir(self):
        self.currentDir = os.getcwd() + '/'

    def action_1(self):
        print("action 1")

    def action_2(self):
        print("action 2")

    def action_3(self):
        print("action 3")

    def action_4(self):
        print("action 4")

    def visu_1(self):
        self.add_visu_frame(nbEntry = True, nbTest = 200)

    def visu_2(self):
        self.add_visu_frame(nbEntry = True, nbTest = 200)

    def visu_3(self):
        self.add_visu_frame(secondFile = True, nbEntry = True, nbTest = 1)

    def visu_4(self):
        self.add_visu_frame(secondFile = True, nbEntry = True, nbTest = 1)

    def add_visu_frame(self, secondFile = False, nbEntry = False, nbTest = 0):
        rows = 0
        self.VisuFrame = ttk.Frame(self.StatsFrame)
        self.VisuFrame.grid(column = 0, row = 2)
        if secondFile:
            self.secondFileFrame = ttk.LabelFrame(self.VisuFrame,\
                text="Select an executable to compare with")
            self.secondFileFrame.grid(column=0, row = rows)
            rows += 1
            self.SFileButton = ttk.Button(self.secondFileFrame,\
                text = "Browse file", command = self.change_s_file)
            self.SFileButton.grid(column = 0, row = 0)

    def change_s_file(self):
        self.s_file = filedialog.askopenfilename(initialdir = self.currentDir,\
            title="pick a file")
        self.label = ttk.Label(self.SecondFileFrame, text="")
        self.label.grid(column = 1, row = 2)
        self.label.configure(text=self.s_file)

    statsValues = [\
        {"text":"Graph", "visu":visu_1, "action":action_1},\
        {"text":"Mean for N inputs", "visu":visu_2, "action":action_2},\
        {"text":"Mean comparaison", "visu":visu_3, "action":action_3},\
        {"text":"Graph comparaison", "visu":visu_4, "action":action_4}]

root = Root()
root.mainloop()
