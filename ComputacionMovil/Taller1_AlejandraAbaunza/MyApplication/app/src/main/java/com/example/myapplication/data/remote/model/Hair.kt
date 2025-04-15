package com.example.myapplication.data.remote.model

import kotlinx.serialization.Serializable

@Serializable
data class Hair(
    val color: String,
    val type: String
)