def solution(survey, choices):
    answer = ''
    mbti = {"R":0, "T":0, "C":0, "F":0, "J":0, "M":0, "A":0, "N":0}

    for idx,choice in enumerate(choices):
        if choice>=4:
            mbti[survey[idx][1]] += choice - 4
        else:
            mbti[survey[idx][0]] += 4 - choice

    type = ""
    if mbti["R"] >= mbti["T"]:
        type += "R"
    else:
        type += "T"

    if mbti["C"] >= mbti["F"]:
        type += "C"
    else:
        type += "F"

    if mbti["J"] >= mbti["M"]:
        type += "J"
    else:
        type += "M"

    if mbti["A"] >= mbti["N"]:
        type += "A"
    else:
        type += "N"

    return type


survey = ["AN", "CF", "MJ", "RT", "NA"]	
choices = 	[5, 3, 2, 7, 5]

print(solution(survey,choices))